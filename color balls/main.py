import pygame
import sys

from basket import Basket

pygame.init()

window_width, window_height = 350, 700


screen = pygame.display.set_mode((window_width, window_height))

basket_red = Basket("violet", 50, 50)
basket_blue = Basket("blue", 100, 100)

baskets = [basket_red, basket_blue]

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.MOUSEBUTTONDOWN:
            for basket in baskets:
                if basket.posX < event.pos[0] < basket.posX + basket.width and basket.posY < event.pos[1] < basket.posY + basket.height:
                    basket.dragging = True
                    basket.offset_x = basket.posX - event.pos[0]
                    basket.offset_y = basket.posY - event.pos[1]

        if event.type == pygame.MOUSEBUTTONUP:
            for basket in baskets:
                basket.dragging = False

        if event.type == pygame.MOUSEMOTION:
            for basket in baskets:
                if basket.dragging:
                    basket.posX = event.pos[0] + basket.offset_x
                    basket.posY = event.pos[1] + basket.offset_y

    screen.fill((0, 0, 0))
    for basket in baskets:
        basket.draw(screen)

    pygame.display.flip()
