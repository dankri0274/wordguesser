$platform = ""

$scriptArgs = $args
$switch = $scriptArgs[0]

if ([string]::IsNullOrEmpty($switch)) {
	Write-Host "Please specify the target platform: -m (macOS), -l (Linux), -w (Windows)"
	exit 1
}

if ($switch -eq "-m") {
	$platform = "macos"
}
elseif ($switch -eq "-l") {
	$platform = "linux"
}
elseif ($switch -eq "-w") {
	$platform = "windows"
}

if ([string]::IsNullOrEmpty($platform)) {
	Write-Host "Invalid platform: $switch"
	exit 1
}

if ($platform -eq "macos" -or $platform -eq "linux") {
	gcc -o game game.c
}
elseif ($platform -eq "windows") {
	gcc -o game.exe game.c
}
