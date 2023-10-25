from Buffer import Buffer
from Controlador import Controlador
import random
class Consumidor(Buffer):
    estaTrabajando = False
    def __init__(self):
        self.productosConsumidos = 0
        self.index = 0
        self.x_index = 0
    def consumir(self):
        if not Controlador.estaTrabajando:
            Consumidor.estaTrabajando = True
            self.productosConsumidos = random.randint(4, 7)
            productos_consumidos_exitosos = 0
            for _ in range(self.productosConsumidos):
                found = False
                for _ in range(Buffer.max):
                    if Buffer.productos[self.x_index] == '|X|':
                        found = True
                        break
                    self.x_index = (self.x_index + 1) % Buffer.max
                if found:
                    self.index = self.x_index
                    self.marcar_posicion_desocupada(self.index)
                    Buffer.productos[self.index] = '|-|'
                    self.x_index = (self.x_index + 1) % Buffer.max
                    productos_consumidos_exitosos += 1
                else:
                    break
            Consumidor.estaTrabajando = False
            self.capturar_mensaje("Productos consumidos: " + str(productos_consumidos_exitosos) +" de " +str(self.productosConsumidos))

            if productos_consumidos_exitosos == 0:
                self.capturar_mensaje("Se intentaron consumir: " + str(self.productosConsumidos) + " (buffer vacío)")
            return True
        return False
    def capturar_mensaje(self, mensaje):
        self.mensaje = mensaje
