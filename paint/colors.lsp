(ql:quickload "lispbuilder-sdl")

(load "gradient.lsp")
(load "globales.lsp")
(load "show-init.lsp")
;(load "pointer.lsp")

(defun default-cursor (gcolor)
  (sdl:draw-box-* 150 0 182 200 :color (sdl:color :r 160 :g 160 :b 160))
  (sdl:draw-box-* 190 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))

  ;Schäfft das Farbverlauf
  (loop for i from 0 to 255 by 5
       do (sdl:draw-box-* (+ 200 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) i 0) :g (if (= *g* 255) i 0) :b (if (= *b* 255) i 0))))
  (loop for i from 0 to 255 by 5
       do (sdl:draw-box-* (+ 251 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) 255 i) :g (if (= *g* 255) 255 i) :b (if (= *b* 255) 255 i))))
  (sdl:draw-filled-circle-* 251 23 15 :color gcolor)
  (sdl:draw-line-* 251 39 251 49 :color sdl:*black*)
  (sdl:draw-line-* 251 50 251 59 :color sdl:*white*)
  (sdl:draw-filled-circle-* 251 47 4 :color (sdl:color :r 0 :g 0 :b 0))
  (sdl:draw-filled-circle-* 251 60 5)
  (sdl:update-display))

(defun maj-color (x y)

  ;Ändert die iniz-farbe
  
  ;Schwarz
  (when (and (sdl:mouse-left-p) (>= x 1) (<= x 21) (>= y 21) (<= y 41))
	(setf *cur-color* sdl:*black*)
	(setf *r* 0) (setf *g* 0) (setf *b* 0) (default-cursor sdl:*black*)
	(sdl:update-display))
  
  ;Blau
  (when (and (sdl:mouse-left-p) (>= x 43) (<= x 63) (>= y 42) (<= y 62))
	(setf *cur-color* sdl:*blue*)
	(setf *r* 0) (setf *g* 0) (setf *b* 255) (default-cursor sdl:*blue*)
	(sdl:update-display))
  
  ;Grün
  (when (and (sdl:mouse-left-p) (>= x 64) (<= x 84) (>= y 42) (<= y 62))
	(setf *cur-color* sdl:*green*)
	(setf *r* 0) (setf *g* 255) (setf *b* 0) (default-cursor sdl:*green*)
	(sdl:update-display))
  
  ;Gelb
  (when (and (sdl:mouse-left-p) (>= x 85) (<= x 105) (>= y 42) (<= y 62))
	(setf *cur-color* sdl:*yellow*)
	(setf *r* 255) (setf *g* 255) (setf *b* 0) (default-cursor sdl:*yellow*)
	(sdl:update-display))
  
  ;Rot
  (when (and (sdl:mouse-left-p) (>= x 22) (<= x 42) (>= y 42) (<= y 62))
	(setf *cur-color* sdl:*red*)
	(setf *r* 255) (setf *g* 0) (setf *b* 0) (default-cursor sdl:*red*)
	(sdl:update-display))
  
  ;Cyan
  (when (and (sdl:mouse-left-p) (>= x 106) (<= x 126) (>= y 42) (<= y 62))
	(setf *cur-color* sdl:*cyan*)
	(setf *r* 0) (setf *g* 255) (setf *b* 255) (default-cursor sdl:*cyan*)
	(sdl:update-display))
  
  ;Magenta
  (when (and (sdl:mouse-left-p) (>= x 1) (<= x 21) (>= y 42) (<= y 62))
	(setf *cur-color* sdl:*magenta*)
	(setf *r* 255) (setf *g* 0) (setf *b* 255) (default-cursor sdl:*magenta*)
	(sdl:update-display)))


(defun colors (list)

  ;Inizialisiert die Fenster
  (sdl:window 800 800 :title-caption (cadr list))
     (sdl:clear-display sdl:*white*)
	 
	 ;Einstellt die Standard-fps zu 200
     (setf (sdl:frame-rate) 60)

	 ;Säubert die Toolbar
	 (sdl:draw-box-* 0 0 800 200 :color (sdl:color :r 160 :g 160 :b 160))

	 (sdl:draw-box-* 190 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))
	 (sdl:draw-box-* 370 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))

	 (sdl:draw-shape (list (sdl:point :x 380 :y 47) (sdl:point :x 482 :y 40) (sdl:point :x 482 :y 55) (sdl:point :x 380 :y 47)) :color sdl:*white*)

     (sdl:draw-line-* 431 50 431 59 :color sdl:*white*)
     (sdl:draw-filled-circle-* 431 47 4 :color (sdl:color :r 0 :g 0 :b 0))
     (sdl:draw-filled-circle-* 431 60 5)
     (setf *brush-size* (/ (- 431 379) 5))

	   ;Schäfft das Farbverlauf
	 (loop for i from 0 to 255 by 5
	     do (sdl:draw-box-* (+ 200 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) i 0) :g (if (= *g* 255) i 0) :b (if (= *b* 255) i 0))))
	 (loop for i from 0 to 255 by 5
	     do (sdl:draw-box-* (+ 251 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) 255 i) :g (if (= *g* 255) 255 i) :b (if (= *b* 255) 255 i))))
	 (show-init)
	 (default-cursor sdl:*blue*)
	 
  	 (sdl:update-display)
	 (sdl:with-events ()
	     (:quit-event () t)
	     (:key-down-event ()
		   (when (sdl:key-state-p :sdl-key-escape)
			 (sdl:push-quit-event)))
	     (:idle ()

		   ;Überpruft die Toolbar
		   (gradient (sdl:mouse-x) (sdl:mouse-y))
		   (maj-color (sdl:mouse-x) (sdl:mouse-y))
		   ;(pointer (sdl:mouse-x) (sdl:mouse-y))
		
		   ;Erlaubt jdm zu zeichnet, wenn die Mouse benutzen sind
		   ;Zeichnt
		   (when (and (equal *cursor* 'carré) (> (sdl:mouse-y) 200) (sdl:mouse-left-p))
			   (sdl:draw-box (sdl:rectangle-from-midpoint-* (sdl:mouse-x) (sdl:mouse-y) *brush-size* *brush-size*)
	               :color *cur-color*))
		   
		   (when (and (equal *cursor* 'rond) (> (sdl:mouse-y) 200) (sdl:mouse-left-p))
			   (sdl:draw-filled-circle-* (sdl:mouse-x) (sdl:mouse-y) (/ *brush-size* 2) :color *cur-color*))
		   
		   ;Auslöscht
		   (when (and (equal *cursor* 'carré) (> (sdl:mouse-y) 200) (sdl:mouse-right-p))
			   (sdl:draw-box (sdl:rectangle-from-midpoint-* (sdl:mouse-x) (sdl:mouse-y) *brush-size* *brush-size*)))

			(sdl:update-display))))

(defun main (argv)
  (colors argv)
  (sb-ext:exit))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
