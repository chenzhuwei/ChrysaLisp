(import 'sys/list/list.inc)
(import 'class/hash_map/hash_map.inc)

(def-class 'component 'hash_map)
(def-method 'init 'class/component/init 'static '(r0 r1))
(def-method 'find_owner 'class/component/find_owner 'static '(r0) '(r0 r1))
(def-method 'emit 'class/component/emit 'static '(r0 r1) '(r0))
(def-method 'get_prop_sym 'class/component/get_prop_sym 'static '(r0 r1) '(r0 r1))
(def-method 'get_prop 'class/component/get_prop 'static '(r0 r1) '(r0 r1))
(def-method 'ref_prop 'class/component/ref_prop 'static '(r0 r1) '(r0 r1))
(def-method 'set_long_prop 'class/component/set_long_prop 'static '(r0 r1 r2) '(r0))
(def-method 'get_long_prop 'class/component/get_long_prop 'static '(r0 r1) '(r0 r1))
(def-method 'set_font_prop 'class/component/set_font_prop 'static '(r0 r1 r2 r3) '(r0))
(def-method 'set_string_prop 'class/component/set_string_prop 'static '(r0 r1 r2) '(r0))

(def-struct 'component 'hash_map)
	(ptr 'tcb)
	(long 'id)
(def-struct-end)

;;;;;;;;;;;;
; properties
;;;;;;;;;;;;

(defcvar '*props* (list))
(defun defprop (_)
	(defcvar (sym-cat "prop_" _) (length *props*))
	(push *props* _))

(defprop "font")
(defprop "text")
(defprop "color")
(defprop "border")
(defprop "min_width")
(defprop "min_height")
(defprop "text_color")
(defprop "flow_flags")
(defprop "grid_width")
(defprop "grid_height")
(defprop "progress_val")
(defprop "progress_max")
(defprop "vdu_width")
(defprop "vdu_height")
