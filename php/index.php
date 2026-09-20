<?php
require_once __DIR__ . '/CinemaFilm.php';
session_start();

$genres = [
	'action', 'comedy', 'drama', 'horror', 'romance', 'sci-fi', 'thriller', 'documentary',
	'animation', 'adventure', 'fantasy', 'mystery', 'musical', 'western', 'crime', 'biography',
	'family', 'war', 'sport', 'history', 'news', 'reality', 'talk show', 'game show', 'variety',
	'short', 'experimental', 'silent', 'cult', 'classic', 'independent', 'foreign', 'art house',
	'avant-garde', 'surrealist', 'expressionist', 'neo-realist', 'postmodernist', 'new wave', 'dogme 95',
	'mockumentary', 'found footage', 'slasher', 'psychological thriller', 'superhero', 'martial arts',
	'spy', 'heist', 'disaster', 'zombie', 'post-apocalyptic', 'dystopian', 'steampunk', 'cyberpunk',
	'space opera', 'time travel', 'alternate history', 'historical fiction', 'biographical drama',
	'political thriller', 'legal drama', 'medical drama', 'sports drama', 'teen drama', 'coming-of-age',
	'road', 'buddy', 'ensemble cast', 'anthology', 'experimental narrative', 'nonlinear narrative',
	'metafictional', 'self-reflexive', 'mockumentary style'
];

if (!isset($_SESSION['filmList'])) {
	$_SESSION['filmList'] = [];
}

$filmList = &$_SESSION['filmList'];
$errors = [];
$message = '';
$editingFilm = null;
$formData = [
	'filmCode' => '',
	'filmTitle' => '',
	'filmGenre' => '',
	'filmDuration' => '',
	'ticketPrice' => '',
	'filmRating' => '',
	'filmImage' => ''
];

function escapeHtml($value)
{
	return htmlspecialchars((string) $value, ENT_QUOTES, 'UTF-8');
}

function getFilmByCode($filmList, $filmCode)
{
	foreach ($filmList as $film) {
		if ($film->getFilmCode() === $filmCode) {
			return $film;
		}
	}

	return null;
}

function validateFilmData($data, $genres, $filmList, $editingCode = '')
{
	$errors = [];

	if (!preg_match('/^CF\d{3}$/', $data['filmCode'])) {
		$errors['filmCode'] = 'code must use the format CF000.';
	}
	else if ($data['filmCode'] !== $editingCode && getFilmByCode($filmList, $data['filmCode']) !== null) {
		$errors['filmCode'] = 'this film code already exists.';
	}

	if ($data['filmTitle'] === '') {
		$errors['filmTitle'] = 'title is required.';
	}

	if (!in_array($data['filmGenre'], $genres, true)) {
		$errors['filmGenre'] = 'please select a valid genre.';
	}

	if (filter_var($data['filmDuration'], FILTER_VALIDATE_INT) === false) {
		$errors['filmDuration'] = 'duration must be a whole number.';
	}
	else if ((int) $data['filmDuration'] < 0 || (int) $data['filmDuration'] > 873) {
		$errors['filmDuration'] = 'duration must be between 0 and 873 minutes.';
	}

	if (filter_var($data['ticketPrice'], FILTER_VALIDATE_INT) === false) {
		$errors['ticketPrice'] = 'ticket price must be a whole number.';
	}
	else if ((int) $data['ticketPrice'] < 0 || (int) $data['ticketPrice'] > 500) {
		$errors['ticketPrice'] = 'ticket price must be between 0 and 500 dollars.';
	}

	if (filter_var($data['filmRating'], FILTER_VALIDATE_INT) === false) {
		$errors['filmRating'] = 'rating must be a whole number.';
	}
	else if ((int) $data['filmRating'] < 0 || (int) $data['filmRating'] > 10) {
		$errors['filmRating'] = 'rating must be between 0 and 10.';
	}

	return $errors;
}

function saveUploadedImage($file, &$errors, $currentImage = '')
{
	if (!isset($file) || $file['error'] === UPLOAD_ERR_NO_FILE) {
		if ($currentImage === '') {
			$errors['filmImage'] = 'an image is required.';
		}

		return $currentImage;
	}

	if ($file['error'] !== UPLOAD_ERR_OK) {
		$errors['filmImage'] = 'the image could not be uploaded.';
		return $currentImage;
	}

	$allowedTypes = ['image/jpeg', 'image/png'];
	$imageType = mime_content_type($file['tmp_name']);
	if (!in_array($imageType, $allowedTypes, true)) {
		$errors['filmImage'] = 'image must be a valid JPG, JPEG, or PNG file.';
		return $currentImage;
	}

	$uploadDirectory = __DIR__ . '/images';
	if (!is_dir($uploadDirectory)) {
		mkdir($uploadDirectory, 0755, true);
	}

	$extension = $imageType === 'image/png' ? 'png' : 'jpg';
	$fileName = uniqid('film_', true) . '.' . $extension;
	$targetPath = $uploadDirectory . '/' . $fileName;
	if (!move_uploaded_file($file['tmp_name'], $targetPath)) {
		$errors['filmImage'] = 'the image could not be saved.';
		return $currentImage;
	}

	return 'images/' . $fileName;
}

if (($_SERVER['REQUEST_METHOD'] ?? '') === 'POST') {
	$action = $_POST['action'] ?? '';

	if ($action === 'delete') {
		$filmCode = $_POST['filmCode'] ?? '';
		foreach ($filmList as $index => $film) {
			if ($film->getFilmCode() === $filmCode) {
				unset($filmList[$index]);
				$filmList = array_values($filmList);
				$message = 'film has been deleted.';
				break;
			}
		}
	}
	else if ($action === 'edit') {
		$filmCode = $_POST['filmCode'] ?? '';
		$editingFilm = getFilmByCode($filmList, $filmCode);
		if ($editingFilm !== null) {
			$formData = [
				'filmCode' => $editingFilm->getFilmCode(),
				'filmTitle' => $editingFilm->getFilmTitle(),
				'filmGenre' => $editingFilm->getFilmGenre(),
				'filmDuration' => $editingFilm->getFilmDuration(),
				'ticketPrice' => $editingFilm->getTicketPrice(),
				'filmRating' => $editingFilm->getFilmRating(),
				'filmImage' => $editingFilm->getFilmImage()
			];
		}
	}
	else if ($action === 'save') {
		$editingCode = $_POST['editingCode'] ?? '';
		$formData = [
			'filmCode' => trim($_POST['filmCode'] ?? ''),
			'filmTitle' => trim($_POST['filmTitle'] ?? ''),
			'filmGenre' => $_POST['filmGenre'] ?? '',
			'filmDuration' => trim($_POST['filmDuration'] ?? ''),
			'ticketPrice' => trim($_POST['ticketPrice'] ?? ''),
			'filmRating' => trim($_POST['filmRating'] ?? ''),
			'filmImage' => $_POST['currentImage'] ?? ''
		];
		$errors = validateFilmData($formData, $genres, $filmList, $editingCode);
		$formData['filmImage'] = saveUploadedImage($_FILES['filmImage'] ?? null, $errors, $formData['filmImage']);

		if (empty($errors)) {
			if ($editingCode !== '') {
				$film = getFilmByCode($filmList, $editingCode);
				if ($film !== null) {
					$film->setFilmCode($formData['filmCode']);
					$film->setFilmTitle($formData['filmTitle']);
					$film->setFilmGenre($formData['filmGenre']);
					$film->setFilmDuration((int) $formData['filmDuration']);
					$film->setTicketPrice((int) $formData['ticketPrice']);
					$film->setFilmRating((int) $formData['filmRating']);
					$film->setFilmImage($formData['filmImage']);
					$message = 'film has been updated.';
				}
			}
			else {
				$filmList[] = new CinemaFilm(
					$formData['filmCode'],
					$formData['filmTitle'],
					$formData['filmGenre'],
					(int) $formData['filmDuration'],
					(int) $formData['ticketPrice'],
					(int) $formData['filmRating'],
					$formData['filmImage']
				);
				$message = 'new film has been added.';
			}

			$formData = array_fill_keys(array_keys($formData), '');
		}
		else if ($editingCode !== '') {
			$editingFilm = getFilmByCode($filmList, $editingCode);
		}
	}
}

$searchCode = trim($_GET['search'] ?? '');
$showAbsoluteCinema = isset($_GET['absoluteCinema']);
$visibleFilms = $filmList;
if ($searchCode !== '') {
	$visibleFilms = array_filter($filmList, function ($film) use ($searchCode) {
		return stripos($film->getFilmCode(), $searchCode) !== false;
	});
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>absolute cinema</title>
	<link rel="preconnect" href="https://fonts.googleapis.com">
	<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
	<link href="https://fonts.googleapis.com/css2?family=IBM+Plex+Mono:wght@400;500;600;700&family=Oxanium:wght@700&display=swap" rel="stylesheet">
	<style>
		:root { color-scheme: dark; --ink: #f0f6fc; --muted: #8b949e; --accent: #f5c518; --accent-hover: #d9ad00; --line: #30363d; --paper: #0d1117; --surface: #161b22; --input: #0d1117; }
		* { box-sizing: border-box; }
		body { margin: 0; background: var(--paper); color: var(--ink); font-family: 'IBM Plex Mono', monospace; }
		main { width: min(1180px, calc(100% - 32px)); margin: 40px auto; }
		header { display: flex; justify-content: space-between; align-items: end; gap: 24px; margin-bottom: 28px; }
		h1 { margin: 0; font-family: 'Oxanium', sans-serif; font-size: clamp(2rem, 5vw, 4.1rem); line-height: 1.1; }
		header p { max-width: 330px; margin: 0 0 5px; color: var(--muted); line-height: 1.5; }
		.layout { display: grid; grid-template-columns: 330px 1fr; gap: 24px; align-items: start; }
		.panel, .tableWrap { background: var(--surface); border: 1px solid var(--line); box-shadow: 8px 8px 0 #010409; }
		.panel { padding: 22px; }
		h2 { margin: 0 0 18px; font-size: 1.4rem; }
		label { display: block; margin: 13px 0 6px; font: 700 0.78rem/1.2 'IBM Plex Mono', monospace; letter-spacing: 0.06em; }
		input, select { width: 100%; padding: 10px 11px; border: 1px solid #484f58; border-radius: 0; background: var(--input); color: var(--ink); font: 1rem 'IBM Plex Mono', monospace; }
		input:focus, select:focus { outline: 2px solid var(--accent); outline-offset: 1px; }
		button, .button { border: 0; padding: 11px 14px; background: var(--accent); color: #111; cursor: pointer; font: 700 0.82rem 'IBM Plex Mono', monospace; letter-spacing: 0.04em; text-decoration: none; }
		button:hover, .button:hover { background: var(--accent-hover); }
		.titleLink { color: inherit; text-decoration: none; }
		.titleLink:hover { color: var(--accent); }
		.cinemaScreen { min-height: 100vh; display: grid; place-items: center; padding: 24px; background: #000; }
		.cinemaScreen img { display: block; width: 100%; height: 100vh; object-fit: contain; }
		.submit { width: 100%; margin-top: 18px; }
		.cancel { display: block; margin-top: 10px; text-align: center; color: var(--muted); font: 0.82rem 'IBM Plex Mono', monospace; }
		.error { margin: 5px 0 0; color: #ff7b72; font: 0.78rem 'IBM Plex Mono', monospace; }
		.notice { padding: 12px 14px; margin-bottom: 18px; background: #12261a; border-left: 4px solid #3fb950; font: 0.9rem 'IBM Plex Mono', monospace; }
		.tableTop { display: flex; justify-content: space-between; align-items: center; gap: 16px; padding: 18px 20px; border-bottom: 1px solid var(--line); }
		.tableTop h2 { margin: 0; }
		.search { display: flex; max-width: 270px; gap: 7px; }
		.search input { min-width: 0; }
		.search button { padding: 10px; }
		.tableScroll { overflow-x: auto; }
		table { width: 100%; border-collapse: collapse; min-width: 760px; }
		th, td { padding: 13px 12px; border-bottom: 1px solid var(--line); text-align: left; vertical-align: middle; }
		th { background: #21262d; font: 700 0.72rem 'IBM Plex Mono', monospace; letter-spacing: 0.06em; }
		td { font-size: 0.95rem; }
		tr:last-child td { border-bottom: 0; }
		.poster { width: 48px; height: 64px; object-fit: cover; display: block; background: #21262d; }
		.empty { padding: 45px 20px; text-align: center; color: var(--muted); }
		.actions { display: flex; gap: 7px; }
		.actions button { padding: 7px 9px; font-size: 0.7rem; }
		.delete { background: #30363d; color: #f0f6fc; }
		@media (max-width: 800px) { main { margin: 24px auto; } header, .layout { display: block; } header p { margin-top: 12px; } .panel { margin-bottom: 24px; } .tableTop { align-items: stretch; flex-direction: column; } .search { max-width: none; } }
	</style>
</head>
<body>
<?php if ($showAbsoluteCinema): ?>
	<a class="cinemaScreen" href="index.php" aria-label="Return to film list">
		<img src="images/absolute_cinema.png" alt="absolute cinema">
	</a>
<?php else: ?>
<main>
	<header>
		<h1><a class="titleLink" href="?absoluteCinema=1">absolute cinema.</a></h1>
		<p>PHP edition.</p>
	</header>

	<?php if ($message !== ''): ?>
		<div class="notice"><?= escapeHtml($message) ?></div>
	<?php endif; ?>

	<div class="layout">
		<section class="panel">
			<h2><?= $editingFilm !== null ? 'edit film' : 'add new film' ?></h2>
			<?php if (!empty($errors)): ?>
				<div class="error">please correct the highlighted fields.</div>
			<?php endif; ?>
			<form method="post" enctype="multipart/form-data">
				<input type="hidden" name="action" value="save">
				<input type="hidden" name="editingCode" value="<?= escapeHtml($editingFilm !== null ? $editingFilm->getFilmCode() : ($_POST['editingCode'] ?? '')) ?>">
				<input type="hidden" name="currentImage" value="<?= escapeHtml($formData['filmImage']) ?>">

				<label for="filmCode">code</label>
				<input id="filmCode" name="filmCode" value="<?= escapeHtml($formData['filmCode']) ?>" required>
				<?php if (isset($errors['filmCode'])): ?><p class="error"><?= escapeHtml($errors['filmCode']) ?></p><?php endif; ?>

				<label for="filmTitle">title</label>
				<input id="filmTitle" name="filmTitle" value="<?= escapeHtml($formData['filmTitle']) ?>" required>
				<?php if (isset($errors['filmTitle'])): ?><p class="error"><?= escapeHtml($errors['filmTitle']) ?></p><?php endif; ?>

				<label for="filmGenre">genre</label>
				<select id="filmGenre" name="filmGenre" required>
					<option value="">Select a genre</option>
					<?php foreach ($genres as $genre): ?>
						<option value="<?= escapeHtml($genre) ?>" <?= $formData['filmGenre'] === $genre ? 'selected' : '' ?>><?= escapeHtml($genre) ?></option>
					<?php endforeach; ?>
				</select>
				<?php if (isset($errors['filmGenre'])): ?><p class="error"><?= escapeHtml($errors['filmGenre']) ?></p><?php endif; ?>

				<label for="filmDuration">duration (minutes)</label>
				<input id="filmDuration" name="filmDuration" type="number" min="0" max="873" value="<?= escapeHtml($formData['filmDuration']) ?>" required>
				<?php if (isset($errors['filmDuration'])): ?><p class="error"><?= escapeHtml($errors['filmDuration']) ?></p><?php endif; ?>

				<label for="ticketPrice">ticket price (US dollars)</label>
				<input id="ticketPrice" name="ticketPrice" type="number" min="0" max="500" value="<?= escapeHtml($formData['ticketPrice']) ?>" required>
				<?php if (isset($errors['ticketPrice'])): ?><p class="error"><?= escapeHtml($errors['ticketPrice']) ?></p><?php endif; ?>

				<label for="filmRating">rating (out of 10)</label>
				<input id="filmRating" name="filmRating" type="number" min="0" max="10" value="<?= escapeHtml($formData['filmRating']) ?>" required>
				<?php if (isset($errors['filmRating'])): ?><p class="error"><?= escapeHtml($errors['filmRating']) ?></p><?php endif; ?>

				<label for="filmImage">image</label>
				<input id="filmImage" name="filmImage" type="file" accept=".jpg,.jpeg,.png,image/jpeg,image/png" <?= $formData['filmImage'] === '' ? 'required' : '' ?>>
				<?php if ($formData['filmImage'] !== ''): ?><p class="error" style="color: var(--muted);">current image will be kept if no new image is selected.</p><?php endif; ?>
				<?php if (isset($errors['filmImage'])): ?><p class="error"><?= escapeHtml($errors['filmImage']) ?></p><?php endif; ?>

				<button class="submit" type="submit"><?= $editingFilm !== null ? 'update film' : 'add film' ?></button>
				<?php if ($editingFilm !== null): ?><a class="cancel" href="index.php">cancel edit</a><?php endif; ?>
			</form>
		</section>

		<section class="tableWrap">
			<div class="tableTop">
				<h2>film list <small>(<?= count($visibleFilms) ?>)</small></h2>
				<form class="search" method="get">
					<input name="search" placeholder="search by code" value="<?= escapeHtml($searchCode) ?>">
					<button type="submit">search</button>
				</form>
			</div>
			<?php if (empty($visibleFilms)): ?>
				<div class="empty">no films found.</div>
			<?php else: ?>
				<div class="tableScroll">
					<table>
						<thead><tr><th>image</th><th>film</th><th>genre</th><th>duration</th><th>price</th><th>rating</th><th>actions</th></tr></thead>
						<tbody>
						<?php foreach ($visibleFilms as $film): ?>
							<tr>
								<td><?php if ($film->getFilmImage() !== ''): ?><img class="poster" src="<?= escapeHtml($film->getFilmImage()) ?>" alt="<?= escapeHtml($film->getFilmTitle()) ?> poster"><?php else: ?><span>no image</span><?php endif; ?></td>
								<td><strong><?= escapeHtml($film->getFilmTitle()) ?></strong><br><small><?= escapeHtml($film->getFilmCode()) ?></small></td>
								<td><?= escapeHtml($film->getFilmGenre()) ?></td>
								<td><?= escapeHtml($film->getFilmDuration()) ?> min</td>
								<td>$<?= escapeHtml($film->getTicketPrice()) ?></td>
								<td><?= escapeHtml($film->getFilmRating()) ?>/10</td>
								<td><div class="actions"><form method="post"><input type="hidden" name="action" value="edit"><input type="hidden" name="filmCode" value="<?= escapeHtml($film->getFilmCode()) ?>"><button type="submit">edit</button></form><form method="post"><input type="hidden" name="action" value="delete"><input type="hidden" name="filmCode" value="<?= escapeHtml($film->getFilmCode()) ?>"><button class="delete" type="submit">delete</button></form></div></td>
							</tr>
						<?php endforeach; ?>
						</tbody>
					</table>
				</div>
			<?php endif; ?>
		</section>
	</div>
</main>
<?php endif; ?>
</body>
</html>
