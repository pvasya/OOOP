import pygame

RED = (255, 0, 0)
BLUE = (0, 0, 255)
VIOLET = (128, 0, 255)
YELLOW = (255, 255, 0)
ORANGE = (255, 128, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)

class Basket:
    def __init__(self, color, x, y):
        self.width, self.height = 50, 50
        self.posX, self.posY = x, y
        self.color = color
        self.dragging = False

    def draw(self, surface):
        if self.color == "red":
            pygame.draw.rect(surface, RED, (self.posX, self.posY, self.width, self.height))
        elif self.color == "blue":
            pygame.draw.rect(surface, BLUE, (self.posX, self.posY, self.width, self.height))
        elif self.color == "orange":
            pygame.draw.rect(surface, ORANGE, (self.posX, self.posY, self.width, self.height))
        elif self.color == "cyan":
            pygame.draw.rect(surface, CYAN, (self.posX, self.posY, self.width, self.height))
        elif self.color == "green":
            pygame.draw.rect(surface, GREEN, (self.posX, self.posY, self.width, self.height))
        elif self.color == "yellow":
            pygame.draw.rect(surface, YELLOW, (self.posX, self.posY, self.width, self.height))
        elif self.color == "violet":
            pygame.draw.rect(surface, VIOLET, (self.posX, self.posY, self.width, self.height))
        pygame.draw.circle(surface, (255, 255, 255), (self.posX+5, self.posY+5), self.height/2)
    def size_change(self, sx, sy):
        self.width, self.height = sx, sy