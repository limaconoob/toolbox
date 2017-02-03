(ql:quickload "lispbuilder-sdl")

(load "couleurs.lsp")

(defconstant fen-width 800)
(defconstant fen-height 800)

(defvar fond noir)
(defvar forme vert)

(defvar index 0)

(defvar matrix (make-list (* fen-height fen-width) :initial-element noir))

(defun le-cercle (x y rayon)
  (loop for i from 0.0 to 3.14 by (/ 1.0 rayon) do
		(if (= index rayon)
			( )
			(and 
				(print (list 'X (+ x index) 'Y (+ y (nth-value 0 (floor (* (sin i) rayon)))) 'XY (* (+ y (nth-value 0 (floor (* (sin i) rayon)))) fen-width) 'RETOUR (+ x index (* (+ y (nth-value 0 (floor (* (sin i) rayon)))) fen-width))))
				(setf (nth (+ x index (* (+ y (nth-value 0 (floor (* (sin i) rayon)))) fen-width)) matrix) rouge)
				(setf (nth (+ x index (* (- y (nth-value 0 (floor (* (sin i) rayon)))) fen-width)) matrix) rouge)
				(setf index (+ index 1)))))
	(setf index 0))

(defvar tmp)

(defun fenster (list)
  (sdl:window fen-width fen-height :title-caption (cadr list))
  (setf (sdl:frame-rate) 60)
	(le-cercle 200 100 50)
	(print (list-length matrix))
	;(print matrix)
	(setf tmp matrix)
	(sdl:with-pixel (pix (sdl:fp sdl:*default-display*))
		(loop for y from 0 to fen-height by 1 do
			(loop for x from 0 to fen-width by 1 do
				(and
					(if (and (or (< y 400) (> y 500)) (not (null tmp)))
						(sdl:write-pixel pix x y (nth 0 tmp))
						(if (not (null tmp))
							(sdl:write-pixel pix x y forme)
							(sdl:write-pixel pix x y noir)))
					(setf tmp (cdr tmp))))))
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
