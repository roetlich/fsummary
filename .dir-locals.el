
                                        ; This file sets emacs variables that are helpful for editing stellar-core

(
 (nil .
      ((eval . (setq default-directory
                       (locate-dominating-file buffer-file-name
                                               ".dir-locals.el")
                       )))
      (compile-command . "make build-debug")
      (eval . (add-to-    list 'auto-mode-alist '("\\.h\\'" . c-mode)))
      )
 (c-mode . (
            ()
            (indent-tabs-mode .  nil)
            (flycheck-clang-language-standard . "c99")
            (flycheck-gcc-language-standard . "c99")
            (flycheck-clang-include-path "src"
                                         "dependencies"
                                         "../dependencies"
                                         )
            (flycheck-gcc-include-path "src"
                                       "dependencies"
                                       "../dependencies"
                                       )
            (whitespace-style . (face tabs tab-mark trailing lines-tail empty))
            (c-file-style . "llvm")
            (eval . (if (boundp 'c-offsets-alist)))))
 )
