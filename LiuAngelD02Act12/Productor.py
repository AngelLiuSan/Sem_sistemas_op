import random
from Buffer import Buffer
from Controlador import Controlador
class Productor(Buffer):
    estaTrabajando = False
    def __init__(self):
        self.productosProducidos = 0
        self.index = 0
        self.x_index = 0
    def producir(self):
        if not Controlador.estaTrabajando:
            Productor.estaTrabajando = True
            numeros= [4, 5, 6, 7]
            self.productosProducidos = random.choice(numeros)
            productos_producidos_exitosos = 0

            for _ in range(self.productosProducidos):
                found = False
                for _ in range(Buffer.max):
                    if Buffer.productos[self.x_index] != '|X|':
                        found = True
                        break
                    self.x_index = (self.x_index + 1) % Buffer.max

                if found:
                    self.index = self.x_index
                    self.marcar_posicion_utilizada(self.index)
                    Buffer.productos[self.index] = '|X|'
                    self.x_index = (self.x_index + 1) % Buffer.max
                    productos_producidos_exitosos += 1
                else:
                    break
            Productor.estaTrabajando = False
            self.capturar_mensaje("Productos producidos: " + str(productos_producidos_exitosos) +" de " +str(self.productosProducidos))
            if productos_producidos_exitosos == 0:
                self.capturar_mensaje("Se intentaron producir: " + str(self.productosProducidos) + " (buffer lleno)")
            return True
        return False
    def capturar_mensaje(self, mensaje):
        self.mensaje = mensaje
