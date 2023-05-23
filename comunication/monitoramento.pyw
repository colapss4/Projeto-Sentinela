import serial
import PySimpleGUI as sg
import time


# Defini o tema da interface gráfica
sg.theme('dark grey 9')

# Configurar a porta serial
porta_serial = serial.Serial('COM3', 9600)  # Altere para a porta serial correta

while True:
    # Verificar se há dados disponíveis na porta serial
    if porta_serial.in_waiting > 0:
        # Ler os dados da porta serial
        dado = porta_serial.read().decode().strip()

        # Verificar se o sinal do Arduino foi recebido
        if dado == '1':
            # Exibir o popup
            sg.popup('Sua Postura Está Incorreta')   

    # Adicionar um pequeno atraso para não consumir muito processamento
    time.sleep(0.1)

