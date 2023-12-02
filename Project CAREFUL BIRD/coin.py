import pygame
from random import randint

class Coin(pygame.sprite.Sprite):
    def __init__(self, width):
        self.width = width
        self.x = randint(int(width/7),int(width-width/7))
        self.y = randint(int(width/15),int(width-width/2))
        pygame.sprite.Sprite.__init__(self)
        self.img = pygame.transform.scale(pygame.image.load('img/coin.png'),(self.width/20,self.width/20))
        self.img_rect = self.img.get_rect(topleft=( self.x,self.y))
        self.up = True
        self.timer = 1

    def update(self,width):
        self.width = width
        self.img = pygame.transform.scale(pygame.image.load('img/coin.png'),(self.width/20,self.width/20))
        if self.up == True:
            self.y-=width/200
            self.timer+=1
        elif self.up == False:
            self.y+=width/200
            self.timer-=1
        if self.timer > 30 or self.timer < 2:
            self.up = not self.up
        self.img_rect = self.img.get_rect(topleft=( self.x,self.y))
            