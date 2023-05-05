# PiPico-Mame-Keyboard
## Uma implementação de teclado USB HID usando Raspberry Pi Pico, com as teclas no padrão do emulador MAME  
  
<hr>
<h3>Como instalar:</h3>  
  
  - Conecte sua Pico no PC segurando o botão "boot"  
  - Depois que um novo drive removível aparecer, copie o arquivo "PiPico-Mame-Keyboard.uf2"   para a pasta base dessa nova unidade.  
  - Pronto!
  
<hr>
<h3>Como fazer a conexão dos botões:</h3>
  
  - A configuração padrão segue na órdem os GPs de 0 até 28, pulando os ausêntes 23, 24 e 25.
  - Cada GP vai para um respectivo pino do botão.
  - Um terra em comum é utilizado para os demais pinos.  
  
<p align=center>  
  
|         Tecla       | Pico | Função       |
|---------------------|------|--------------|
|  F2                 | GP0  |  SERVICE     |
|  9                  | GP1  |  TEST        |
|  5                  | GP3  |  COIN1       |
|  6                  | GP2  |  COIN2       |
|  1                  | GP4  |  P1 START    |
|  SETA PARA CIMA     | GP5  |  P1 CIMA     |
|  SETA PARA BAIXO    | GP6  |  P1 BAIXO    |
|  SETA PARA ESQUERDA | GP7  |  P1 ESQUERDA |
|  SETA PARA DIREITA  | GP8  |  P1 DIREITA  |
|  CTRL ESQUERDO      | GP9  |  P1 Botão 1  |
|  ALT ESQUERDO       | GP10 |  P1 Botão 2  |
|  ESPAÇO             | GP11 |  P1 Botão 3  |
|  SHIFT ESQUERDO     | GP12 |  P1 Botão 4  |
|  z                  | GP13 |  P1 Botão 5  |
|  x                  | GP14 |  P1 Botão 6  |
|  2                  | GP15 |  P2 START    |
|  r                  | GP16 |  P2 CIMA     |
|  f                  | GP17 |  P2 BAIXO    |
|  d                  | GP18 |  P2 ESQUERDA |
|  g                  | GP19 |  P2 DIREITA  |
|  a                  | GP20 |  P2 Botão 1  |
|  s                  | GP21 |  P2 Botão 2  |
|  q                  | GP22 |  P2 Botão 3  |
|  w                  | GP26 |  P2 Botão 4  |
|  e                  | GP27 |  P2 Botão 5  |
|  h                  | GP28 |  P2 Botão 6  |
  
</p>  
<hr>
<h3>Uso de Encoder:</h3>
  
Este código também é compatível com um encoder para ESQUERDA e DIREITA do Player 1.
Para tal, conecte seu encoder como a seguir:  
  
<p align=center> 
  
| Encoder | Pico |
|---------|------|
| CLK ou A| GP8  |
| DT  ou B| GP7  |
| +/VCC:  | +3v3 |
| GND:    | GND  |
  
</p>  
  
Para ativar o modo encoder, conecte ou inicie a Pico segurando o GP28 apertado, ou seja,
conectado no GND.  
  
Você pode manter tanto o encoder quanto o direcional conectados ao mesmo tempo.  
  
<hr>
<h3>Como compilar com suas próprias alterações:</h3>  
  
  - Instale o Arduino IDE 1.x;  
  - Adicione o núcleo "arduino pico". Insira a linha abaixo em File->Preferences->"Additional Boards Manager URLs":  
    https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json  
  
  - Instale a biblioteca "RotaryEncoder" em Sketch->Include Library->Manage Libraries;
  - Selecione a placa correta em Tools->Boards->Raspberry Pi RP2040 Boards;
  - Compile e se divirta!
  
  
  