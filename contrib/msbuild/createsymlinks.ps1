if($args.Length -ne 1) {
    if(Test-Path "command-list.txt") {
        $args = ,"command-list.txt";
    } else {
        Write-Output ".\buildall.ps1 (command-list.txt from git dir)";
        exit 1;
    }
}
foreach ($line in Get-Content $args[0] | where {$_ -match '^git-.*'} ) {
    $name = $line.Substring(0, $line.IndexOf(' ')) + ".exe"
    if((Test-Path $name) -eq $false) {
        New-Item $name -ItemType SymbolicLink -Value "git.exe"
    }
}
if((Test-Path "git-remote-http.exe") -eq $false) {
    New-Item git-remote-http.exe -Type SymbolicLink -Value git-remote-curl.exe
}
if((Test-Path "git-remote-https.exe") -eq $false) {
    New-Item git-remote-https.exe -Type SymbolicLink -Value git-remote-curl.exe
}