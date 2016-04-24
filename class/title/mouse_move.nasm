%include 'inc/func.inc'
%include 'inc/gui.inc'
%include 'class/class_title.inc'
%include 'class/class_window.inc'

	fn_function class/title/mouse_move
		;inputs
		;r0 = window object
		;r1 = mouse event message
		;trashes
		;all but r0, r4

		def_structure	local
			def_long	local_inst
			def_long	local_window
			def_long	local_event
			def_long	local_old_x
			def_long	local_old_y
		def_structure_end

		;save old window bounds
		vp_sub local_size, r4
		vp_cpy r0, [r4 + local_inst]
		vp_cpy r1, [r4 + local_event]
		vp_cpy [r0 + view_parent], r0
		vp_cpy [r0 + view_parent], r0
		vp_cpy r0, [r4 + local_window]
		vp_cpy [r0 + view_x], r8
		vp_cpy [r0 + view_y], r9
		vp_cpy r8, [r4 + local_old_x]
		vp_cpy r9, [r4 + local_old_y]

		;dirty old area
		static_call window, dirty

		;get new window position
		vp_cpy [r4 + local_inst], r0
		vp_cpy [r4 + local_window], r1
		vp_cpy [r0 + title_last_x], r8
		vp_cpy [r0 + title_last_y], r9
		static_call title, get_relative
		vp_cpy [r4 + local_event], r1
		vp_sub [r1 + ev_data_x], r8
		vp_sub [r1 + ev_data_y], r9
		vp_mul -1, r8
		vp_mul -1, r9

		;change window position
		vp_cpy [r4 + local_window], r0
		vp_cpy r8, [r0 + view_x]
		vp_cpy r9, [r0 + view_y]

		;translate old dirty area and dirty all
		vp_sub [r4 + local_old_x], r8
		vp_sub [r4 + local_old_y], r9
		vp_mul -1, r8
		vp_mul -1, r9
		vp_add view_dirty_region, r0
		static_call gui_region, translate
		static_call window, dirty_all, '[r4 + local_window]'

		vp_cpy [r4 + local_inst], r0
		vp_add local_size, r4
		vp_ret

	fn_function_end
