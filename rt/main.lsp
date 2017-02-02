(ql:quickload "lispbuilder-sdl")

(load "couleurs.lsp")

(defconstant fen-width 800)
(defconstant fen-height 800)
(defvar matrix (make-list fen-height :initial-element (make-list fen-width :initial-element 255)))

(defvar color noir)

(defun fenster (list)
  (sdl:window fen-width fen-height :title-caption (cadr list))
	(sdl:with-pixel (pix (sdl:fp sdl:*default-display*))
		(loop for y from 0 to fen-height by 1 do
			(loop for x from 0 to fen-width by 1 do
				(sdl:write-pixel pix x y color))))
  (setf (sdl:frame-rate) 60)
  (sdl:update-display)
	(sdl:with-events ()
	  (:quit-event () t)
	  (:key-down-event ()
			(when (sdl:key-state-p :sdl-key-escape)
				(sdl:push-quit-event)))
	  (:idle ()
			;; CODE ;;
			(sdl:update-display))))

(defun main (argv)
  (fenster argv)
  (sb-ext:exit))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
