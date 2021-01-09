:autocmd BufNewFile *.cpp 0r ~/.vim/templates/basic_cpp.cpp

set autoindent
set smartindent

nnoremap <C-S> :update<CR>
inoremap <C-S> <Esc>:update<CR>

nnoremap <C-Q> :q<CR>
inoremap <C-Q> <Esc>:q<CR>

set laststatus=2
set statusline+=%F

set ruler

autocmd FileType c,cpp setlocal equalprg=clang-format
