# Introdução #
O site oficial (http://opencv.willowgarage.com/wiki/) possui documentação incompleta sobre a instalação e que não aborda versões diferentes de sistemas operacionais. Como as máquinas para desenvolvimento do trabalho foram ubuntu 11.10 64bits e MacOS X 10.06, foi necessário a compilação manual com configurações específicas.

---

# Ubuntu 11.10  Oneric Ocelot #
  * Primeiro devemos instalar as dependências:
sudo apt-get install build-essential checkinstall git pkg-config cmake libpng12-0 libpng12-dev libpng++-dev libpng3 libpnglite-dev libpngwriter0-dev libpngwriter0c2 libfaac-dev libjack-jackd2-dev libjasper-dev libjasper-runtime libjasper1 libmp3lame-dev libopencore-amrwb-dev libsdl1.2-dev libtheora-dev libva-dev libvdpau-dev libvorbis-dev libx11-dev libxfixes-dev libxvidcore-dev texi2html yasm zlib1g-dev zlib1g-dbg zlib1g libgstreamer0.10-0 libgstreamer0.10-dev libgstreamer0.10-0-dbg gstreamer0.10-tools gstreamer0.10-plugins-base libgstreamer-plugins-base0.10-dev gstreamer0.10-plugins-good gstreamer0.10-plugins-ugly gstreamer0.10-plugins-bad gstreamer0.10-ffmpeg pngtools libtiff4-dev libtiff4 libtiffxx0c2 libtiff-tools libjpeg8 libjpeg8-dev libjpeg8-dbg libjpeg-prog libavcodec-dev libavcodec52 libavformat52 libavformat-dev libxine1-ffmpeg libxine-dev libxine1-bin libunicap2 libunicap2-dev libdc1394-22-dev libdc1394-22 libdc1394-utils swig python-numpy  libpython2.7 python-dev python2.7-dev libjpeg-progs libjpeg-dev libgtk2.0-0 libgtk2.0-dev

  * Baixar e instalar x264()[ftp://ftp.videolan.org/pub/videolan/x264/snapshots/](ftp://ftp.videolan.org/pub/videolan/x264/snapshots/)), baixar qualquer pacote, extrair para uma pasta e usar os comandos:
    1. ./configure --enable-static --enable-pic --enable-shared
    1. make
    1. sudo make install

  * Baixar e instalar o ffmpeg(http://ffmpeg.org/download.html), baixar qualquer pacote, extrair para uma pasta e usar os comandos:
  1. ./configure --enable-gpl --enable-libfaac --enable-libmp3lame -- enable-libopencore-amrnb --enable-libopencore-amrwb --enable-libtheora --enable-libvorbis --enable-libx264 --enable-libxvid --enable-nonfree --enable-postproc --enable-version3 --enable-x11grab --enable-pic --enable-shared
  1. make
  1. sudo make install

  * Baixar e instalar o v4l(http://www.linuxtv.org/downloads/v4l-utils/), baixar qualquer pacote, extrair para uma pasta e usar os comandos:
  1. make
  1. sudo make install

  * Baixar e instalar o openCV, baixar versão 2.3.1a, extrair para uma pasta e usar os comandos:
  1. Entrar na pasta de extração
  1. mkdir release
  1. cd release
  1. cmake -D CMAKE\_BUILD\_TYPE=RELEASE -D CMAKE\_INSTALL\_PREFIX=/usr/local     -D BUILD\_PYTHON\_SUPPORT=ON -D BUILD\_EXAMPLES=ON ..
  1. make
  1. sudo make install
  1. sudo gedit /etc/ld.so.conf.d/opencv.conf e adicionar a linha /usr/local/lib
  1. sudo ldconfig
  1. sudo gedit /etc/bash/bash.bashrc e adicionar as duas linhas
    * PKG\_CONFIG\_PATH=$PKG\_CONFIG\_PATH:/usr/local/lib/pkgconfig
    * export PKG\_CONFIG\_PATH
  1. Reiniciar o sistema


---

# MacOS X 10.06 #
> Exatamente como no video
> http://www.youtube.com/watch?v=i9hYiMXLZRs


---

# Integração com QT #
> Para integrar o openCV com QT basta adicionar no arquivo de configuração do projeto as linhas:
  * CONFIG += link\_pkgconfig
  * PKGCONFIG += opencv