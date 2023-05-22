import PySimpleGUI as sg
import win32gui, win32con


sg.theme('dark grey 9')
sg.popup('Sua Postura Esta incorreta')


sg = win32gui.GetForegroundWindow()
win32gui.ShowWindow(sg , win32con.SW_HIDE)