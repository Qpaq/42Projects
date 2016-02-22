#!/bin/sh
echo "Gotta fix brew..."
rm -rf ~/.brew
echo "## Homebrew fix" >> ~/.zshrc.local
echo "export HOMEBREW_CACHE=/tmp/mycache" >> ~/.zshrc.local
echo "export HOMEBREW_TEMP=/tmp/mytemp" >> ~/.zshrc.local
echo "mkdir -p /tmp/mytemp /tmp/mycache ~/Library/Caches/Homebrew" >> ~/.zshrc.local
echo "### End of the Homebrew fix" >> ~/.zshrc.local
source ~/.zshrc
/usr/local/bin/brew update
echo "\x1b[32mDone!\x1b[0m"
