" **************************************************************************** "
"                                                                              "
"                                                         :::      ::::::::    "
"    .vimrc                                             :+:      :+:    :+:    "
"                                                     +:+ +:+         +:+      "
"    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         "
"                                                 +#+#+#+#+#+   +#+            "
"    Created: 2015/12/05 12:16:11 by snicolet          #+#    #+#              "
"    Updated: 2015/12/06 12:46:34 by snicolet         ###   ########.fr        "
"                                                                              "
" **************************************************************************** "

set nu
set ruler
set colorcolumn=80
set hlsearch
set smartindent
set cindent
syntax on
map <F7> mzgg=G`z
filetype plugin indent on
inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap { {}<Esc>i
inoremap #in #include <Esc>i
inoremap #d #define <Esc>i
inoremap " ""<Esc>i
inoremap ' ''<Esc>i
highlight NoSpacesEOL ctermbg=red ctermfg=white guibg=#592929
highlight DoublesSpaces ctermbg=blue
match NoSpacesEOL / \+$/
match DoublesSpaces / \ \ /
set backupdir=~/.vim/
