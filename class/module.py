class Restaurant():
    """classe para anunciar a descrição e a abertura de um restaurante
    """
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
        self.number_served = 0
    
    def describe_restaurant(self):
        print("O restaurante chamado " + self.restaurant_name.title() + " possui a culinária do tipo " + self.cuisine_type.title()+ ".")
        
    def open_restaurant(self):
        print("O restaurante " + self.restaurant_name.title() + " está aberto.")
     
    def set_number_served(self, value):
        self.number_served = value
        print("O restaurante atendeu " + str(self.number_served) + " clientes.")
        
    def increment_number_served(self, value):
        self.number_served += value
        print("O restaurante atendeu " + str(self.number_served) + " clientes.")