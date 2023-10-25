class Buffer:
    max = 20
    productos = ["|-|"] * max
    posiciones_utilizadas = set()
    mensaje = ""
    asterisk_index = 0

    def __init__(self):
        for i in range(Buffer.max):
            Buffer.productos[i] = '|-|'

    def marcar_posicion_utilizada(self, index):
        self.posiciones_utilizadas.add(index)

    def marcar_posicion_desocupada(self, index):
        self.posiciones_utilizadas.discard(index)

    @staticmethod
    def obtener_producto(index):
        return Buffer.productos[index]

    @staticmethod
    def marcar_producto(index, valor):
        Buffer.productos[index] = valor
