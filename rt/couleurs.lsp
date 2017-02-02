
(defconstant bleu 4278190080)
(defconstant vert 16711680)
(defconstant rouge 65280)
(defconstant cyan (logior bleu vert))
(defconstant magenta (logior bleu rouge))
(defconstant jaune (logior vert rouge))
(defconstant noir 0)
(defconstant blanc (logior bleu vert rouge))

(defconstant show 255)
(defconstant hide 0)
