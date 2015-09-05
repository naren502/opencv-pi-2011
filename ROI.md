# Introdução #
Este post irá explicar a parte inicial do trabalho.Como reconhecer os números das cédulas de dinheiro.
# Detalhes #
Primeiro foi selecionado a região de interesse por proporção da localização dos números nas notas. Como exemplo foram feitas para notas de 2/5 reais e 50 reais.

Problemas:
  * Exige figuras com muita qualidade
  * Necessário modelos para notas com quantidade de números diferentes.

Após a seleçao da ROI, a imagem é modificada para escala de cinza e o reconhecimento de números é feito pela biblioteca tesseract-ocr(code.google.com/p/tesseract-ocr/).