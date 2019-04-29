if($args.Length != 1) {
    Write-Output ".\buildall.ps1 (command-list.txt from git dir)";
    exit 1;
}
foreach ($line in Get-Content $args[0] | where {$_ -match '^git-.*'} ) {
    $name = $line.Substring(0, $line.IndexOf(' ')) + ".exe"
    if((Test-Path $name) -eq $false) {
        New-Item $name -ItemType SymbolicLink -Value "git.exe"
    }
}
New-Item git-remote-http.exe -Type SymbolicLink -Value git-remote-curl.exe
New-Item git-remote-https.exe -Type SymbolicLink -Value git-remote-curl.exe