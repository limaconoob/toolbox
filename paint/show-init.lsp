(load "globales.lsp")

(defun show-init ()

  ;Säubert die Toolbar
  ;(sdl:draw-box-* 0 0 800 200 :color (sdl:color :r 255 :g 255 :b 255))
  ;Iniz das Farbverlauf
  (when (and (>= (sdl:mouse-x) 190) (<= (sdl:mouse-x) 312) (sdl:mouse-left-p))
	(sdl:draw-box-* 150 0 182 200 :color (sdl:color :r 160 :g 160 :b 160))
	(sdl:draw-box-* 190 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))

  ;Schäfft das Farbverlauf
    (loop for i from 0 to 255 by 5
		do (sdl:draw-box-* (+ 200 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) i 0) :g (if (= *g* 255) i 0) :b (if (= *b* 255) i 0))))
    (loop for i from 0 to 255 by 5
		do (sdl:draw-box-* (+ 251 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) 255 i) :g (if (= *g* 255) 255 i) :b (if (= *b* 255) 255 i)))))


  (when (and (>= (sdl:mouse-x) 370) (<= (sdl:mouse-x) 492) (sdl:mouse-left-p))
	(sdl:draw-box-* 330 0 532 200 :color (sdl:color :r 160 :g 160 :b 160))
    (sdl:draw-box-* 370 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))
    (sdl:draw-shape (list (sdl:point :x 380 :y 47) (sdl:point :x 482 :y 40) (sdl:point :x 482 :y 55) (sdl:point :x 380 :y 47)) :color sdl:*white*))


  ;Inizialisiert Backgrounds
  ;(sdl:draw-box-* 0 0 800 200 :color (sdl:color :r 160 :g 160 :b 160))
  (sdl:draw-box-* 0 0 127 63 :color (sdl:color :r 40 :g 40 :b 40))
  ;(sdl:draw-box-* 190 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))
  ;(sdl:draw-box-* 370 30 122 35 :color (sdl:color :r 40 :g 40 :b 40))
  (sdl:draw-line-* 0 200 800 200 :color (sdl:color :r 40 :g 40 :b 40))

  ;Inizialisiert die Standardfarben
  (sdl:draw-box-* 1 42 20 20 :color sdl:*magenta*)
  (sdl:draw-box-* 22 42 20 20 :color sdl:*red*)
  (sdl:draw-box-* 43 42 20 20 :color sdl:*blue*)
  (sdl:draw-box-* 64 42 20 20 :color sdl:*green*)
  (sdl:draw-box-* 85 42 20 20 :color sdl:*yellow*)
  (sdl:draw-box-* 106 42 20 20 :color sdl:*cyan*)

  ;Schäfft ein Blockfarbverlauf (Grau)
  (sdl:draw-box-* 1 21 20 20 :color (sdl:color :r 0 :g 0 :b 0))
  (sdl:draw-box-* 22 21 20 20 :color (sdl:color :r 50 :g 50 :b 50))
  (sdl:draw-box-* 43 21 20 20 :color (sdl:color :r 100 :g 100 :b 100))
  (sdl:draw-box-* 64 21 20 20 :color (sdl:color :r 150 :g 150 :b 150))
  (sdl:draw-box-* 85 21 20 20 :color (sdl:color :r 200 :g 200 :b 200))
  (sdl:draw-box-* 106 21 20 20 :color (sdl:color :r 250 :g 250 :b 250))

  ;Schäfft das Pinselgrößverlauf
  ;(sdl:draw-shape (list (sdl:point :x 380 :y 47) (sdl:point :x 482 :y 40) (sdl:point :x 482 :y 55) (sdl:point :x 380 :y 47)) :color sdl:*white*)
)
  ;Schäfft das Farbverlauf
  ;(loop for i from 0 to 255 by 5
;		do (sdl:draw-box-* (+ 200 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) i 0) :g (if (= *g* 255) i 0) :b (if (= *b* 255) i 0))))
 ; (loop for i from 0 to 255 by 5
;		do (sdl:draw-box-* (+ 251 (/ i 5)) 40 1 15 :color (sdl:color :r (if (= *r* 255) 255 i) :g (if (= *g* 255) 255 i) :b (if (= *b* 255) 255 i)))))
