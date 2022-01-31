let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/w/c++/raytracer/Utilities
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 Constants.h
badd +1 Maths.h
badd +1 Normal.hpp
badd +1 Point2D.hpp
badd +1 Point3D.hpp
badd +1 Vector3D.hpp
badd +1 Maths.cpp
badd +1 Normal.cpp
badd +1 Point2D.cpp
badd +1 Point3D.cpp
badd +1 Vector3D.cpp
badd +1 RGBColor.hpp
badd +1 RGBColor.cpp
badd +1 ShadeRec.hpp
badd +1 ~/w/c++/raytracer/TODO.md
badd +1 ~/w/c++/raytracer/Ray.hpp
badd +1 ~/w/c++/raytracer/Ray.cpp
badd +1 ShadeRec.cpp
badd +1 Ray.hpp
badd +0 Ray.cpp
argglobal
%argdel
$argadd Constants.h
$argadd Maths.h
$argadd Normal.hpp
$argadd Point2D.hpp
$argadd Point3D.hpp
$argadd Vector3D.hpp
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit Constants.h
argglobal
let s:l = 2 - ((1 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
tabnext
edit ~/w/c++/raytracer/TODO.md
argglobal
if bufexists("~/w/c++/raytracer/TODO.md") | buffer ~/w/c++/raytracer/TODO.md | else | edit ~/w/c++/raytracer/TODO.md | endif
balt Constants.h
let s:l = 11 - ((10 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 0
tabnext
edit Maths.h
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
2argu
balt Maths.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
2argu
if bufexists("Maths.cpp") | buffer Maths.cpp | else | edit Maths.cpp | endif
balt Maths.h
let s:l = 2 - ((1 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit Normal.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
3argu
balt Normal.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
3argu
if bufexists("Normal.cpp") | buffer Normal.cpp | else | edit Normal.cpp | endif
balt Normal.hpp
let s:l = 2 - ((1 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit Point2D.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
4argu
balt Point2D.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
4argu
if bufexists("Point2D.cpp") | buffer Point2D.cpp | else | edit Point2D.cpp | endif
balt Point2D.hpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit Point3D.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
5argu
balt Point3D.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
5argu
if bufexists("Point3D.cpp") | buffer Point3D.cpp | else | edit Point3D.cpp | endif
balt Point3D.hpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit Vector3D.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
6argu
balt Vector3D.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
6argu
if bufexists("Vector3D.cpp") | buffer Vector3D.cpp | else | edit Vector3D.cpp | endif
balt Vector3D.hpp
let s:l = 2 - ((1 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit RGBColor.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
1argu
if bufexists("RGBColor.hpp") | buffer RGBColor.hpp | else | edit RGBColor.hpp | endif
balt RGBColor.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
1argu
if bufexists("RGBColor.cpp") | buffer RGBColor.cpp | else | edit RGBColor.cpp | endif
balt RGBColor.hpp
let s:l = 7 - ((6 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 7
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit ShadeRec.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
if bufexists("ShadeRec.hpp") | buffer ShadeRec.hpp | else | edit ShadeRec.hpp | endif
balt ShadeRec.cpp
let s:l = 2 - ((1 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 0
wincmd w
argglobal
if bufexists("ShadeRec.cpp") | buffer ShadeRec.cpp | else | edit ShadeRec.cpp | endif
balt ShadeRec.hpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext
edit Ray.hpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
argglobal
if bufexists("Ray.hpp") | buffer Ray.hpp | else | edit Ray.hpp | endif
balt ShadeRec.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
argglobal
if bufexists("Ray.cpp") | buffer Ray.cpp | else | edit Ray.cpp | endif
balt ~/w/c++/raytracer/Ray.cpp
let s:l = 1 - ((0 * winheight(0) + 24) / 48)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 104 + 104) / 209)
exe 'vert 2resize ' . ((&columns * 104 + 104) / 209)
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=aoOtTIc
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
