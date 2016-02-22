#!/bin/sh
curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh > install_ohmyzsh
sh install_ohmyzsh
brew update && brew upgrade
export PATH="$HOME/.brew/bin:$PATH" >> ~/.zshrc
