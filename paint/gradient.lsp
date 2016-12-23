(load "globales.lsp")
(load "show-init.lsp")

(defun gradient (x y)

  ;Zeichnet die Cursor für die Pinselgröße
	(when (and (sdl:mouse-left-p) (>= x 380) (<= x 482) (< y 80) (> y 20))
	  (show-init)
	  (sdl:draw-line-* x 50 x 59 :color sdl:*white*)
	  (sdl:draw-filled-circle-* x 47 4 :color (sdl:color :r 0 :g 0 :b 0))
	  (sdl:draw-filled-circle-* x 60 5)
	  (setf *brush-size* (/ (- x 379) 5))
	  (sdl:update-display))

  ;Zeichnet die Cursor für die Farbeverlauf
    ;Dunkler Seit
	(when (and (sdl:mouse-left-p) (>= x 200) (<= x 251) (< y 80) (> y 20))
	  (show-init)
	  (sdl:draw-filled-circle-* x 23 15 :color (sdl:color :r (if (= *r* 255) (* (- x 200) 5) 0) :g (if (= *g* 255) (* (- x 200) 5) 0) :b (if (= *b* 255) (* (- x 200) 5) 0)))
	  (sdl:draw-line-* x 39 x 49 :color sdl:*black*)
	  (sdl:draw-line-* x 50 x 59 :color sdl:*white*)
	  (sdl:draw-filled-circle-* x 47 4 :color (sdl:color :r 0 :g 0 :b 0))       
	  (sdl:draw-filled-circle-* x 60 5)
	  (setf *cur-color* (sdl:color :r (if (= *r* 255) (* (- x 200) 5) 0) :g (if (= *g* 255) (* (- x 200) 5) 0) :b (if (= *b* 255) (* (- x 200) 5) 0)))
	  (sdl:update-display))

    ;Lichter Seit
	(when (and (sdl:mouse-left-p) (>= x 252) (<= x 302) (< y 80) (> y 20))

	;Zeichnet eine Runde, dass die aktuelle Farbe nimmst
	  (show-init)
	  (sdl:draw-filled-circle-* x 23 15 :color (sdl:color :r (* (- x 251) 5) :g (* (- x 251) 5) :b 255))
	  (sdl:draw-filled-circle-* x 23 15 :color (sdl:color :r (if (= *r* 255) 255 (* (- x 251) 5)) :g (if (= *g* 255) 255 (* (- x 251) 5)) :b (if (= *b* 255) 255 (* (- x 251) 5))))
	  (sdl:draw-line-* x 39 x 49 :color sdl:*black*)
	  (sdl:draw-line-* x 50 x 59 :color sdl:*white*)
	  (sdl:draw-filled-circle-* x 47 4 :color (sdl:color :r 0 :g 0 :b 0))
	  (sdl:draw-filled-circle-* x 60 5)
	  (setf *cur-color* (sdl:color :r (* (- x 251) 5) :g (* (- x 251) 5) :b 255))
	  (setf *cur-color* (sdl:color :r (if (= *r* 255) 255 (* (- x 251) 5)) :g (if (= *g* 255) 255 (* (- x 251) 5)) :b (if (= *b* 255) 255 (* (- x 251) 5))))
	  (sdl:update-display)))
