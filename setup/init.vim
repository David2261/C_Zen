set mouse=a " enable mouse
set encoding=utf-8
set number
set noswapfile
set scrolloff=5

set tabstop=4
set softtabstop=0
set shiftwidth=0
set autoindent
set fileformat=unix
filetype indent on " load filetype-specific indent files

inoremap jk <esc>


call plug#begin()
Plug 'rip-rip/clang_complete'
Plug 'vim-scripts/bash-support.vim'
Plug 'ekalinin/dockerfile.vim'

call plug#end()


" Turn off search highlight
nnoremap , <space> :nohlsearch <CR>

