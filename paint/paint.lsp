(ql:quickload "lispbuilder-sdl")

(defun empty (list) (= (length list) 0))

(defvar d 20)
(defvar i 0)
(defvar b 0)
(defvar xmax 2000)
(defvar ymax 1500)

(defun get-item (list index)
  (if (empty list) ()
	(if (= 0 index)
	  (first list)
	  (get-item (rest list) (- index 1)))))

(defun coord-case (n d)
  (+ (* (floor n d) d) 1))

(defun eraser (d x y)
  (sdl:draw-box (sdl:rectangle :x (coord-case x d) :y (coord-case y d) :w (- d 1) :h (- d 1))
				:color sdl:*black*))

(defun draw-dot (d x y)
  (sdl:draw-box (sdl:rectangle :x (coord-case x d) :y (coord-case y d) :w (- d 1) :h (- d 1))
				:color sdl:*red*))

(defun vertical (x y k b)
  (loop for i from 0 to y by k
   	do (sdl:draw-line-* 0 (+ i b) x (+ i b)))
  (loop for i from 0 to x by k
   	do (sdl:draw-line-* i y i b)))

(defun init-grid (x y k b)
  (loop for i from 0 to y by k
   	do (sdl:draw-line-* b i x i))
  (loop for i from 0 to x by k
   	do (sdl:draw-line-* (+ i b) y (+ i b) 0)))


(defun init-window (x y k name)
  (sdl:with-init ()
      (sdl:window (+ x 1) (+ y 1) :title-caption name)
      (setf (sdl:frame-rate) 60)
      (sdl:clear-display sdl:*black*)
	  (init-grid x y k 0)
      (sdl:update-display)
	  (sdl:disable-key-repeat)
	  (sdl:initialise-default-font)
	  (sdl:enable-unicode)
	  (sdl:unicode-enabled-p)
      (sdl:with-events ()
	    (:quit-event () t)
		(:key-down-event ())
  		(:idle ()
		 (when (sdl:mouse-left-p)
		   (draw-dot k (sdl:mouse-x) (sdl:mouse-y)))
		 (when (sdl:mouse-right-p)
		   (eraser k (sdl:mouse-x) (sdl:mouse-y)))
		 (sdl:update-display)))))

;(defvar lang 0)
;
;(defun get-language (x y)
;  (if (<= x 400) (setq lang 1) ())
;  (if (<= x 500) (setq lang 2) (setq lang 3)))
;
;(defun menu ()
;  (sdl:with-init ()
;	(sdl:window 600 400 :title-caption "LisPaint Menu")
;	(let (y-pos 0))
;	(sdl:initialise-default-font)
;	(setf (sdl:frame-rate) 20)
;	(sdl:enable-unicode)
;	(sdl:disable-key-repeat)
;	(sdl:with-events ()
;	  (:quit-event () t)
;	  (:key-down-event ())
;	  (:idle ()
;	 	(sdl:clear-display sdl:*white*)
;		(setf y-pos 0)
;		(sdl:draw-string-solid-* (format nil "Select software's language :")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*)
;		(sdl:update-display)
;		(until (> lang 0) (when (sdl:mouse-left-p) (if (and (<= (sdl:mouse-x) 600) (>= (sdl:mouse-x) 300) (<= (sdl:mouse-y) 400) (>= (sdl:mouse-y) 200)) (get-language (sdl:mouse-x) (sdl:mouse-y)) ())) ())
;	 	(sdl:clear-display sdl:*white*)
;		(if (= lang 1)
;		    (sdl:draw-string-solid-* (format nil "Le logiciel est en Français.")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*))
;		    (sdl:draw-string-solid-* (format nil "Veuillez nommer votre image : ")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*)))
;		(if (= lang 2)
;		    (sdl:draw-string-solid-* (format nil "The software is in English.")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*))
;		    (sdl:draw-string-solid-* (format nil "Choose a name for your picture, then press enter : ")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*)))
;		(if (= lang 3)
;		    ((sdl:draw-string-solid-* (format nil "Die Software ist auf Deutsch.")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*)
;		    (sdl:draw-string-solid-* (format nil "Jetzt nennen Sie dein Bild bitte, dann Sie Enter müssen drücken : ")
;								 10 (incf y-pos 15)
;								 :color sdl:*black*
;								 :surface sdl:*default-display*)))
;		  (sdl:update-display)
;		  (when (and (null (sdl:key-state-p :sdl-key-enter)) (sdl:key-state-p)) (draw-character-* (get-char (sdl:key-down-p) /* Afficher le caractère en entrée et le stocker dans un (char *) pour sauvegarder le fichier et le nommer */ )))
;
(defun main (argv)
  (print argv)
;  (menu)
  (init-window (parse-integer (get-item argv 1) :junk-allowed t)
			   (parse-integer (get-item argv 2) :junk-allowed t)
			   d
			   (get-item argv 3)))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
