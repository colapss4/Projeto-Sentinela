import PySimpleGUI as sg
import win32gui
import win32con

# Definir o tema da interface gráfica
sg.theme('dark grey 9')

# Exibir o popup
sg.popup('Sua Postura Está Incorreta')

# Ocultar a janela principal
window = win32gui.GetForegroundWindow()
win32gui.ShowWindow(window, win32con.SW_HIDE)