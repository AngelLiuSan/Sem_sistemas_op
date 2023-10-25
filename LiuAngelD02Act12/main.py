import tkinter as tk
import random
from Productor import Productor
from Consumidor import Consumidor
from Buffer import Buffer

class MainForm:
    def __init__(self, root):
        self.productor = Productor()
        self.consumidor = Consumidor()
        self.buffer = Buffer()
        self.root = root
        root.title("Productor-Consumidor")
        self.lblNumAleatorio = tk.Label(root, text="Número aleatorio: ")
        self.lblNumAleatorio.pack()
        self.lblProductorStatus = tk.Label(root, text="Productor: ", fg="green")
        self.lblProductorStatus.pack()
        self.lblConsumidorStatus = tk.Label(root, text="Consumidor: ", fg="gray")
        self.lblConsumidorStatus.pack()
        self.lblProductorMessage = tk.Label(root, text="", fg="gray")
        self.lblProductorMessage.pack()
        self.lblConsumidorMessage = tk.Label(root, text="", fg="gray")
        self.lblConsumidorMessage.pack()
        self.buffer_frame = tk.Frame(root)
        self.buffer_frame.pack()
        self.asterisk_index = 0
        self.update_interface()
    def update_interface(self):
        numAleatorio = random.randint(0, 99)
        self.lblNumAleatorio.config(text="Número aleatorio: " + str(numAleatorio).zfill(2))
        if numAleatorio % 2 == 0:
            if not self.productor.estaTrabajando:
                self.lblProductorStatus.config(text="Productor: trabajando", fg="green")
                self.lblConsumidorStatus.config(text="Consumidor: dormido", fg="gray")
                produccion_exitosa = self.productor.producir()
                if produccion_exitosa:
                    self.lblProductorMessage.config(text=self.productor.mensaje, fg="green")
                    self.lblConsumidorMessage.config(text=self.consumidor.mensaje,fg="gray")
                else:
                    self.lblProductorMessage.config(text="Intento de producción (___) - Buffer lleno", fg="green")
        else:
            if not self.consumidor.estaTrabajando:
                self.lblProductorStatus.config(text="Productor: dormido", fg="gray")
                self.lblConsumidorStatus.config(text="Consumidor: trabajando", fg="green")
                consumo_exitoso = self.consumidor.consumir()
                if consumo_exitoso:
                    self.lblProductorMessage.config(text=self.productor.mensaje,fg="gray")
                    self.lblConsumidorMessage.config(text=self.consumidor.mensaje, fg="green")
                else:
                    self.lblConsumidorMessage.config(text="Intento de consumo (___) - Buffer vacío", fg="green")
        for i, producto in enumerate(self.buffer.productos):
            row = i // 4
            col = i
            row1 = 5
            col1 = i
            char_to_display = "|X|" if producto == '|X|' else '|-|'
            label = tk.Label(self.buffer_frame, text=char_to_display, font=("Arial", 18), width=5, height=2)
            number_label = tk.Label(self.buffer_frame, text=str(i + 1), font=("Arial", 12), width=5, height=2)
            number_label.grid(row=row1, column=col1)
            label.grid(row=row, column=col)
        self.asterisk_index += 1
        if self.asterisk_index >= Buffer.max:
            self.asterisk_index = 0
        self.root.after(1000, self.update_interface)
if __name__ == "__main__":
    root = tk.Tk()
    app = MainForm(root)
    root.bind("<Escape>", lambda e: root.destroy())
    root.mainloop()
