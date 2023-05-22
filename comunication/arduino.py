from win10toast import ToastNotifier
import win32gui, win32con


#inicializar

mensagem = ToastNotifier()

mensagem.show_toast(
    "SENTINELA",
    "Sua Postura Está Incorreta.",
    threaded= True,
    icon_path= None, #(img.jpg)
    duration= 20 #segundos
)

mensagem = win32gui.GetForegroundWindow()
win32gui.ShowWindow(mensagem , win32con.SW_HIDE)