import pygame
import json
import os.path
from random import randint

from player import Player
from spike import Spike
from coin import Coin

class Game():
    def __init__(self) -> None:
        self.score = 0

        if os.path.isfile('carefulbird.json'):
            try:
                with open("carefulbird.json", "r") as jsfile:
                    jsdata = json.load(jsfile)
                    if jsdata and isinstance(jsdata[0], dict):
                        jsdata = jsdata[0]
                        self.score = jsdata.get('score', self.score)

            except json.decoder.JSONDecodeError:
                print("Error decoding JSON.")
        else:
            print("JSON file not found.")

    def run(self):
        pygame.mixer.pre_init(44100,-16,1,512)
        pygame.init()
        window_width = 750
        window_height = 500

        clock = pygame.time.Clock()
        tmpscore = 0
        pygame.mixer.music.load('sounds/bg.wav')
        mcoin =pygame.mixer.Sound('sounds/coin.wav')
        mgameover =pygame.mixer.Sound('sounds/gameover.wav')
        mflap=pygame.mixer.Sound('sounds/flap.wav')
        pygame.mixer.music.set_volume(0.05)
        pygame.mixer.music.play(-1)

        screen = pygame.display.set_mode((window_width, window_height),pygame.RESIZABLE)
        icon = pygame.image.load('img/icon.png').convert()
        pygame.display.set_icon(icon)
        pygame.display.set_caption("CAREFUL BIRD")
        bg = pygame.image.load('img/bg.png').convert_alpha()
        bg1 = pygame.image.load('img/bg1.png').convert_alpha()
        fl = pygame.image.load('img/full.png').convert_alpha()
        fla = pygame.image.load('img/fullactive.png').convert_alpha()
        min = pygame.image.load('img/min.png').convert_alpha()
        mina = pygame.image.load('img/minactive.png').convert_alpha()

        m = pygame.image.load('img/mute.jpg').convert_alpha()
        ma = pygame.image.load('img/muteactive.jpg').convert_alpha()
        unm = pygame.image.load('img/unmute.jpg').convert_alpha()
        unma = pygame.image.load('img/unmuteactive.jpg').convert_alpha()

        isfl = False
        ismute = False
 
        c = 1
        music_timer = pygame.USEREVENT + 1
        pygame.time.set_timer(music_timer,1000)
        ismutea = False
        running = True
        coin = Coin(750)

        pl = Player(750)

        spl = Spike(750,0)
        spr = Spike(750,1)

        rigth = True
        run = True
        once = True
        start = True
        start1 = True
        while running:
            width, heigth = screen.get_size()
            widthwin = 750
            heigthwin = 500
            mouse = pygame.mouse.get_pos()
            keys = pygame.key.get_pressed()
            x = 0
            y = 0
            

            if not ismute and c == 1:
                pygame.mixer.music.play(-1)
                c = 0
            elif ismute:
                pygame.mixer.music.stop()
                c = 1

            if width/heigth >= 1.5:
                heigthwin = heigth
                widthwin = heigthwin*1.5
                x = (width - widthwin)/2
            else:
                widthwin = width
                heigthwin = widthwin/1.5
                y = (heigth - heigthwin)/2
            sc = heigthwin/10
            
            fl1 = pygame.transform.scale(fl,(sc,sc))
            fla1 = pygame.transform.scale(fla,(sc,sc))
            min1 = pygame.transform.scale(min,(sc,sc))
            mina1 = pygame.transform.scale(mina,(sc,sc))
            m1 = pygame.transform.scale(m,(sc,sc))
            ma1 = pygame.transform.scale(ma,(sc,sc))
            un1 = pygame.transform.scale(unm,(sc,sc))
            unma1 = pygame.transform.scale(unma,(sc,sc))

            pygame.draw.rect(screen,'Black',(x,y,x+widthwin-sc,y+heigthwin))
            pygame.draw.aalines(screen,'White',True,[(x, y),(x + widthwin,y),(x + widthwin,y+heigthwin),(x,y+heigthwin),(x,y)])
            pygame.draw.aalines(screen,'White',True,[(x+widthwin-sc, y),(x + widthwin-sc,y+heigthwin)])
            pygame.draw.aalines(screen,'White',True,[(x+widthwin-sc, y+2*sc),(x + widthwin,y+2*sc)])
            pygame.draw.aalines(screen,'White',True,[(x, y+sc),(x + widthwin,y+sc)])

            font = pygame.font.SysFont("Arial", int(sc))
            lscore = font.render('Score: '+str(int(tmpscore)),False,'White')
            
            cfl = fl1.get_rect(topleft=(x+widthwin-sc,y))
            cm = m1.get_rect(topleft=(x+widthwin-sc,y+sc))
            imgbg = pygame.transform.scale(bg,(widthwin-sc,heigthwin-heigthwin/10))
            screen.blit(imgbg,(x,y+sc,widthwin-sc,heigthwin-heigthwin/10))

            bfont = pygame.font.SysFont("Arial", int(sc/2))

            if run:
                if not start1:
                    screen.blit(pl.img,(pl.x,pl.y))
                    pl.update(widthwin)
                    if keys[pygame.K_SPACE]:
                        if not ismute:
                            mflap.play()
                        pl.y -= widthwin/50

                    pl.y += widthwin/200

                    if rigth:
                        pl.x += widthwin/200
                    else:
                        pl.x -= widthwin/200

                    if pl.x > x+widthwin-2*sc:
                        pl.img1 = pygame.transform.flip(pl.img1, True, False)
                        rigth = not rigth
                        spl.y = randint(0,int(spr.width/1.5))
                        spl.x = x

                    if pl.x < x:
                        pl.img1 = pygame.transform.flip(pl.img1, True, False)
                        rigth = not rigth
                        spr.y = randint(0,int(spl.width/1.5))
                        spr.x = x+widthwin-1.5*sc

                    screen.blit(spl.img,(spl.x,spl.y))
                    screen.blit(spr.img,(spr.x,spr.y))
                    spl.update(widthwin)
                    spr.update(widthwin)
                
                    screen.blit(coin.img,(coin.x,coin.y))
                    coin.update(widthwin)
                    
                    if pl.img_rect.colliderect(coin.img_rect):
                        tmpscore+=5
                        coin.x = randint(int(x+sc/2+width/7),int(width-width/7-sc/2-x))
                        coin.y = randint(int(y+sc/2+width/7),int(width-width/2-sc/2-y))
                    screen.blit(lscore,(x,y))
                    start1 = False

            if start:
                bg1 = pygame.transform.scale(bg1,(widthwin-sc,heigthwin))
                screen.blit(bg1,(x,y))
                lgo = font.render('Careful Bird ',False,'Red')
                lscore = font.render('Max score: '+str(int(self.score)),False,'Red')
                screen.blit(lgo,(x+widthwin/4,y+heigthwin/4))
                screen.blit(lscore,(x+widthwin/4,y+heigthwin/4+heigthwin/8))
                lpress = font.render('Press Space to start',False,'Red')
                screen.blit(lpress,(x+widthwin/4,y+heigthwin/4+heigthwin/4))
                if keys[pygame.K_SPACE]:
                    once = True
                    pl.x = widthwin/2
                    pl.y = heigthwin/2
                    tmpscore = 0
                    start = False
                    start1 = False

            if pl.img_rect.colliderect(spl.img_rect) or pl.img_rect.colliderect(spr.img_rect) or pl.y<sc or pl.y>y+heigthwin-sc:
                if not ismute and once:
                    mgameover.play()
                once = False 
                run = False
                pygame.draw.rect(screen,'Gray',(x,y,x+widthwin-sc,y+heigthwin))
                lgo = font.render('Game over!   Score: '+str(int(tmpscore)),False,'Red')
                screen.blit(lgo,(x+widthwin/4,y+heigthwin/4))
                lpress = font.render('Press R to restart',False,'Red')
                screen.blit(lpress,(x+widthwin/4,y+heigthwin/4+heigthwin/8))
                if keys[pygame.K_r]:
                    once = True
                    pl.x = widthwin/2
                    pl.y = heigthwin/2
                    tmpscore = 0
                    run = True


            if not ismute:
                screen.blit(m1,(x+widthwin-sc,y+sc,100,100))
                if cm.collidepoint(mouse):
                    screen.blit(ma1,(x+widthwin-sc,y+sc,100,100))
                    if not ismutea and pygame.mouse.get_pressed()[0]:
                        ismute = not ismute
                        ismutea = True

            else:
                screen.blit(un1,(x+widthwin-sc,y+sc,100,100))
                if cm.collidepoint(mouse):
                    screen.blit(unma1,(x+widthwin-sc,y+sc,100,100))
                    if not ismutea and pygame.mouse.get_pressed()[0]:
                        ismute = not ismute
                        ismutea = True



            if not isfl:
                screen.blit(fl1,(x+widthwin-sc,y,100,100))
                if cfl.collidepoint(mouse):
                    screen.blit(fla1,(x+widthwin-sc,y,100,100))
                    if pygame.mouse.get_pressed()[0]:
                        isfl = not isfl
                        screen = pygame.display.set_mode((window_width, window_height),pygame.FULLSCREEN)
                        pygame.display.update()

            else:
                screen.blit(min1,(x+widthwin-sc,y,100,100))
                if cfl.collidepoint(mouse):
                    screen.blit(mina1,(x+widthwin-sc,y,100,100))
                    if pygame.mouse.get_pressed()[0]:
                        isfl = not isfl
                        screen = pygame.display.set_mode((window_width, window_height),pygame.RESIZABLE)
                        pygame.display.update()



            pygame.display.update()
            for event in pygame.event.get():
                if event.type == music_timer:
                    ismutea = False
                elif event.type == pygame.VIDEORESIZE:
                    spl.y = 1000
                    spr.y = 1000 
                    coin.x = widthwin/2
                    coin.y = heigthwin/2
                if event.type == pygame.QUIT:
                    if tmpscore>self.score:
                        self.score = tmpscore
                    with open("carefulbird.json", "w") as jsfile:
                        json.dump([{'score':self.score}], jsfile, indent=2)
                    running = False
                    pygame.quit()
            clock.tick(60)