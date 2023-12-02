import pygame
from random import randint

class Player(pygame.sprite.Sprite):
    def __init__(self, width):
        self.width = width
        self.x = width/2
        self.y = width/8
        pygame.sprite.Sprite.__init__(self)
        file = ''
        if randint(0,1)==0:
            self.img1 = pygame.image.load('img/yellow.png').convert_alpha()
        else:
            self.img1 = pygame.image.load('img/red.png').convert_alpha()
        
        self.img = pygame.transform.scale(self.img1,(self.width/17,self.width/17))
        self.img_rect = self.img.get_rect(topleft=( self.x,self.y))

    def update(self,width):
        self.width = width
        self.img = pygame.transform.scale(self.img1,(self.width/17,self.width/17))
        self.img_rect = self.img.get_rect(topleft=( self.x,self.y))

