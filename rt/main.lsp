(ql:quickload "lispbuilder-sdl")

(load "couleurs.lsp")

(defconstant fen-width 800)
(defconstant fen-height 800)

(defvar fond noir)
(defvar forme vert)

(defun le-cercle (plan x y rayon)
  (loop for i from 0.0 to 3.14 by (/ 1.0 rayon) do
		(print (+ x i))
		;plan[y + (nth-value 0 (floor (* (sin i) rayon)))][x + i]
		;plan[y - (nth-value 0 (floor (* (sin i) rayon)))][x + i]
		(print (nth-value 0 (floor (* (sin i) rayon)))))
)

(defvar matrix (make-list fen-height :initial-element (make-list fen-width :initial-element 255)))

(defun fenster (list)
  (sdl:window fen-width fen-height :title-caption (cadr list))
	(sdl:with-pixel (pix (sdl:fp sdl:*default-display*))
		(loop for y from 0 to fen-height by 1 do
			(loop for x from 0 to fen-width by 1 do
				(if (or (< y 400) (> y 500))
					(sdl:write-pixel pix x y fond)
					(sdl:write-pixel pix x y forme)))))
  (setf (sdl:frame-rate) 60)
  (sdl:update-display)

	(le-cercle matrix 400 400 50)

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
