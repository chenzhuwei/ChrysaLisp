(import 'sys/class.inc)
(import 'sys/code.inc)

(def-class 'gui_region)
(def-method 'translate 'gui/region/translate 'static '(r1 r7 r8))
(def-method 'bounds 'gui/region/bounds 'static '(r1) '(r7 r8 r9 r10))
(def-method 'clip_rect 'gui/region/clip_rect 'static '(r0 r1 r7 r8 r9 r10) '(r0))
(def-method 'remove_rect 'gui/region/remove_rect 'static '(r0 r1 r7 r8 r9 r10) '(r0))
(def-method 'cut_rect 'gui/region/cut_rect 'static '(r0 r1 r2 r7 r8 r9 r10) '(r0))
(def-method 'copy_rect 'gui/region/copy_rect 'static '(r0 r1 r2 r7 r8 r9 r10) '(r0))
(def-method 'paste_rect 'gui/region/paste_rect 'static '(r0 r1 r7 r8 r9 r10) '(r0))
(def-method 'free 'gui/region/free 'static '(r0 r1) '(r0))
(def-method 'copy_region 'gui/region/copy_region 'static '(r0 r1 r2 r3 r7 r8) '(r0))
(def-method 'paste_region 'gui/region/paste_region 'static '(r0 r1 r2 r7 r8) '(r0))
(def-method 'remove_region 'gui/region/remove_region 'static '(r0 r1 r2 r7 r8) '(r0))

(def-struct 'gui_rect 'ln_fnode)
	(int 'x)
	(int 'y)
	(int 'x1)
	(int 'y1)
(def-struct-end)
