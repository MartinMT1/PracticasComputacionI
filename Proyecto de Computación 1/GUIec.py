# Interfaz gráfica para calculadora de electrónica
import tkinter as tk
from tkinter import *
from PIL import Image, ImageTk
from tkinter import messagebox
import webbrowser

# Creando interfaz
interfaz = tk.Tk()
interfaz.title("Calculadora de electrónica")
interfaz.geometry("500x450")

# Funciones para los botones
def salida():
    salir = messagebox.askquestion("Salir", "¿Desea salir?")
    if salir == 'yes':
        interfaz.quit()
        interfaz.destroy()

def abrirVentana():
    LeyOhm = tk.Toplevel(interfaz)
    LeyOhm.geometry("500x400")
    LeyOhm.title("Ley de Ohm")
    LeyOhmbv = tk.Label(LeyOhm, text="Ley de Ohm", font=("Times new roman", 14), )
    LeyOhmbv.pack(side=TOP)

    # Read the Image
    ohmpng = Image.open("ohm3.png")

    # Resize the image using resize() method
    resize_OHM = ohmpng.resize((378, 263))

    ohmpng2 = ImageTk.PhotoImage(resize_OHM)

    # create label and add resize image
    labelohm = Label(LeyOhm, image=ohmpng2)
    labelohm.image = ohmpng2
    labelohm.pack(side=TOP)

    # Texto
    labelohm2 = Label(LeyOhm, text="La ley de Ohm establece que la tensión entre los extremos  \n"
                                " de materiales conductores es directamente proporcional\n"
                                " a la corriente que fluye a través del material",font=("Times new roman", 12))
    labelohm2.pack(side=TOP)


    btn = Button(LeyOhm,text= "Cerrar",command=lambda: LeyOhm.destroy())
    btn.pack(side=BOTTOM)



def abrirVentana2():
    Colores = tk.Toplevel(interfaz)
    Colores.geometry("1000x500")
    Colores.title("Bandas de colores")
    Coloresbv = tk.Label(Colores, text="Resistencias", font=("Times new roman", 14), )
    Coloresbv.pack(side=TOP)

    # Read the Image
    colorespng = Image.open("colores.png")

    # Resize the image using resize() method
    resize_colores = colorespng.resize((906, 366))

    colopng2 = ImageTk.PhotoImage(resize_colores)

    # create label and add resize image
    labelcolo = Label(Colores, image=colopng2)
    labelcolo.image = colopng2
    labelcolo.pack(side=TOP)

    # Texto
    labelcolo2 = Label(Colores, text="Los fabricantes recurren a un código de colores\n"
                                     " que se imprime en franjas sobre las resistencias\n "
                                     "con el fin de permitir al usuario saber de que valor\n "
                                     "es la resistencia con la que está trabajando ", font=("Times new roman", 12))
    labelcolo2.pack(side=TOP)

    btn = Button(Colores,text= "Cerrar",command=lambda: Colores.destroy())
    btn.pack(side=BOTTOM)

def abrirVentana3():
    diodo = tk.Toplevel(interfaz)
    diodo.geometry("400x500")
    diodo.title("Diodo LED")
    Coloresbv = tk.Label(diodo, text="Diodos LED", font=("Times new roman", 14), )
    Coloresbv.pack(side=TOP)

    # Read the Image
    ledpng = Image.open("LED2.png")

    # Resize the image using resize() method
    resize_led = ledpng.resize((310, 229))

    ledpng2 = ImageTk.PhotoImage(resize_led)

    # create label and add resize image
    labelled = Label(diodo, image=ledpng2)
    labelled.image = ledpng2
    labelled.pack(side=TOP)

    # Texto
    labelled2 = Label(diodo, text="Para calcular la resistencia de un diodo LED se hace uso de\n "
                                  "la Ley de Ohm y de los valores conocidos para cada color\n."
                                  " Después de hacer los despejes obtenemos que:\n"
                                  "V – Vled = I x R\n"
                                  "R = (Vfuente – Vled) / I", font=("Times new roman", 12))
    labelled2.pack(side=TOP)

    btn = Button(diodo, text="Cerrar", command=lambda: diodo.destroy())
    btn.pack(side=BOTTOM)

def abrirVentana4():
    Capa = tk.Toplevel(interfaz)
    Capa.geometry("850x600")
    Capa.title("Capacitores")
    Capabv = tk.Label(Capa, text="Capacitores", font=("Times new roman", 14), )
    Capabv.pack(side=TOP)

    # Read the Image
    capapng = Image.open("capa2.png")

    # Resize the image using resize() method
    resize_capa = capapng.resize((803, 364))

    capapng2 = ImageTk.PhotoImage(resize_capa)

    # create label and add resize image
    labelcapa = Label(Capa, image=capapng2)
    labelcapa.image = capapng2
    labelcapa.pack(side=TOP)

    # Texto
    labelcapa2 = Label(Capa, text="La capacitancia se expresa como la relación entre la carga eléctrica de \n"
                                  "cada conductor y la diferencia de potencial (es decir, tensión) entre ellos.\n "
                                  "(Se mide en Faradios.)\n"
                                  "Para calcular el tiempo en el que se carga un capacitor tenemos la fórmula:\n "
                                  "T = RxC. \n"
                                  "Donde la resistencia R está en ohmios, el condensador \n"
                                  "C en milifaradios  (mF) y el resultado está en milisegundos.", font=("Times new roman", 12))
    labelcapa2.pack(side=TOP)

    btn = Button(Capa, text="Cerrar", command=lambda: Capa.destroy())
    btn.pack(side=BOTTOM)

def abrirVentana5():
    Indu = tk.Toplevel(interfaz)
    Indu.geometry("800x600")
    Indu.title("Inductores")
    Indubv = tk.Label(Indu, text="Inductores", font=("Times new roman", 14), )
    Indubv.pack(side=TOP)

    # Read the Image
    indupng = Image.open("indu2.png")

    # Resize the image using resize() method
    resize_indu = indupng.resize((721, 449))

    indupng2 = ImageTk.PhotoImage(resize_indu)

    # create label and add resize image
    labelindu = Label(Indu, image=indupng2)
    labelindu.image = indupng2
    labelindu.pack(side=TOP)

    # Texto
    labelindu2 = Label(Indu, text="Los inductores son elementos pasivos que tienen la característica de \n "
                                  "almacenamiento de energía en forma de campo magnético\n"
                                  "Por el efecto electromagnético de un inductor se genera una oposición\n"
                                  " al flujo de electrones con una equivalencia en Ohms", font=("Times new roman", 12))
    labelindu2.pack(side=TOP)

    btn = Button(Indu, text="Cerrar", command=lambda: Indu.destroy())
    btn.pack(side=BOTTOM)

def callback(url):
    webbrowser.open_new_tab(url)


# Creando etiquetas
Bienvenida = tk.Label(interfaz, text="Calculadora de electrónica", font=("Times new roman", 12),)
Bienvenida.grid(row=0, column=1, pady=5, padx=5)

Etiqueta1 = tk.Label(interfaz, text="Recursos didácticos", font=("Times new roman", 10),)
Etiqueta1.grid(row=1, column=1, pady=5, padx=5)



btnlink = Button(interfaz, text="Ir a calculadora",font=('Times new roman', 15),bg="Cyan3")
btnlink.grid(column=1, row=8)
btnlink.bind("<Button-1>", lambda e:
callback("https://www.onlinegdb.com/fork/yMa_FT4u5"))


# Imágenes para los botones
Ohm = Image.open('LeyDeOhm.jpg')
Ohm = Ohm.resize((110, 110))
Ohm = ImageTk.PhotoImage(Ohm)

Res = Image.open('resistencia.jpg')
Res = Res.resize((110, 110))
Res = ImageTk.PhotoImage(Res)

led = Image.open('led.jpg')
led = led.resize((110, 110))
led = ImageTk.PhotoImage(led)

cap = Image.open('cap.jpg')
cap = cap.resize((110, 110))
cap = ImageTk.PhotoImage(cap)

ind = Image.open('ind.jpg')
ind = ind.resize((110, 110))
ind = ImageTk.PhotoImage(ind)

bye = Image.open('bye.jpg')
bye = bye.resize((110, 110))
bye = ImageTk.PhotoImage(bye)

# Etiquetas con imagen
img_et1 = Label(image=Ohm)
img_et1.grid(row=3, column=0)

img_et2 = Label(image=Res)
img_et2.grid(row=3, column=1)

img_et3 = Label(image=led)
img_et3.grid(row=3, column=2)

img_et4 = Label(image=cap)
img_et4.grid(row=5, column=0)

img_et5 = Label(image=ind)
img_et5.grid(row=5, column=1)

img_et6 = Label(image=bye)
img_et6.grid(row=5, column=2)


# Creando botones
boton1 = tk.Button(interfaz, command=abrirVentana, text="Ley de Ohm", height=2, width=20)
boton2 = tk.Button(interfaz, command=abrirVentana2, text="Resistencias", height=2, width=20)
boton3 = tk.Button(interfaz, command=abrirVentana3, text="Diodo LED", height=2, width=20)
boton4 = tk.Button(interfaz, command=abrirVentana4, text="Capacitores", height=2, width=20)
boton5 = tk.Button(interfaz, command=abrirVentana5, text="Inductores", height=2, width=20)
boton6 = tk.Button(interfaz, command=salida, text="Salir", height=2, width=20)


# Ubicando botones en un grid

boton1.grid(row=4, column=0, pady=2, padx=7)
boton2.grid(row=4, column=1, pady=2, padx=2)
boton3.grid(row=4, column=2, pady=2, padx=2)
boton4.grid(row=6, column=0, pady=2, padx=7)
boton5.grid(row=6, column=1, pady=2, padx=2)
boton6.grid(row=6, column=2, pady=2, padx=2)





interfaz.mainloop()
