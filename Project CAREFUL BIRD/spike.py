import pygame
from random import randint

class Spike(pygame.sprite.Sprite):
    def __init__(self,width,lor) -> None:
        self.width = width
        self.x = 0
        self.y = 0
        self.lor = lor
        pygame.sprite.Sprite.__init__(self)
        if self.lor == 0:
            self.img = pygame.transform.scale(pygame.image.load('img/spikel.png'),(self.width/30,self.width/1.5/2))
            self.img_rect = self.img.get_rect(topleft=( self.x,self.y))
            self.x = 0
            self.y = randint(0,self.width/1.5)
        elif self.lor == 1:
            self.img = pygame.transform.scale(pygame.image.load('img/spiker.png'),(self.width/30,self.width/1.5/2))
            self.img_rect = self.img.get_rect(topleft=( self.x,self.y))
            self.x = width - width/10
            self.y = randint(0,self.width/1.5)

    def update(self,width):
        self.width = width
        if self.lor == 0:
            self.img = pygame.transform.scale(pygame.image.load('img/spikel.png'),(self.width/30,self.width/1.5/2))
            self.img_rect = self.img.get_rect(topleft=( self.x,self.y))
        elif self.lor == 1:
            self.img = pygame.transform.scale(pygame.image.load('img/spiker.png'),(self.width/30,self.width/1.5/2))
            self.img_rect = self.img.get_rect(topleft=( self.x,self.y))
