# Jadson de Jesus Santos - Tarefa de Clock e Temporizadores: Alarme

## 📚 Apresentação

Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando o Raspberry Pi Pico W SDK, desenvolvido no VS Code e simulado no Wokwi Online. 
O sistema é acionado através de um botão, utilizando a função de One Shot add_alarm_in_ms() para controlar o tempo de transição entre os estados dos LEDs. 
A sequence_running = false indica que a sequencia só poderá ser iniciada novamente após o término da sequencia atual.

## 🎯 Objetivo

Compreender o funcionamento do temporizador, alarmes de One Shot e implementação de debounce.

## 📑 Requisitos

- Visual Studio Code;
- Extensões C/C++, CMAKE e Raspberry Pi Pico no VSCode;
- Simulador Wokwi Online.

## 📋 Funcionamento

- A API de Hardware add_alarm_in_ms() atua de forma externa ao processador principal;
- O programa inicializa os pinos e entra em um loop de verificação do botão;
- O botão aciona a função de alarme de One Shot, que garante que uma sequência não interrompa outra;
- Todos os LEDs acendem ao pressionar o botão;
- Após 3 segundos, o LED verde desliga;
- Após 3 segundos, o LED vermelho desliga;
- Após 3 segundos, o LED azul desliga.
- O botão só será funcional novamente após o ciclo terminar e todos os LEDs estarem apagados.

## 📷 GIF Ilustrativo
![Alarme](https://github.com/user-attachments/assets/f27e5b67-e8ec-4faf-8aea-be87fd748cf4)
