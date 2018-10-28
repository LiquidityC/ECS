nnoremap <F1> :Make<cr>
nnoremap <F2> :ter ++open ./build/testecs -s<cr>

packadd termdebug
let g:termdebug_wide = 1

let g:syntastic_cpp_compiler_options = '-DDEBUG -std=c++17'
let g:syntastic_cpp_include_dirs = [ 'build/debug', '/usr/include/SDL2' ]
