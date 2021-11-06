
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;

public class Main extends JFrame {
    
    public static void main(String[] args) {
        new Main();
    }
    
    class Score implements Comparable<Score>{

        int score;
        String name;

        public Score(int score, String player){
            this.score = score;
            this.name = player;
        }
        public void setName(String nm)  {   name=nm;    }
        public void setscore(int sc)    {   score=sc;   }
        public String getName()         {   return name;}
        
        public String getScore(){
            int sx=score;
            String sc=Integer.toString(sx);
            return sc;
        }
            
        public int compareTo(Score otherScore){
            if (this.score > otherScore.score)      return -1;
            else if (this.score < otherScore.score) return 1;
            else                                    return this.name.compareTo(otherScore.name);  
        }
    }
    
    /////Main Contentpane
    private JPanel          mainpane;
    /////Game Logo & Button Group
    private JLabel          mainmenu,menuIcon;
    /////Images setting
    private MyImageIcon     menuBGImg = new MyImageIcon("resources/menuBG.png");
    private MyImageIcon     menuIconImg = new MyImageIcon("resources/menuIcon.png").resize(600, 600);
    private MyImageIcon     startButtonImg = new MyImageIcon("resources/startButton.png").resize(300, 300);
    private MyImageIcon     startFadeButtonImg = new MyImageIcon("resources/startFadeButton.png").resize(250, 250);
    private MyImageIcon     scoreButtonImg = new MyImageIcon("resources/scoreButton.png").resize(300, 300);
    private MyImageIcon     scoreFadeButtonImg = new MyImageIcon("resources/scoreFadeButton.png").resize(250, 250);
    private MyImageIcon     exitButtonImg  = new MyImageIcon("resources/exitButton.png").resize(300, 300);
    private MyImageIcon     exitFadeButtonImg  = new MyImageIcon("resources/exitFadeButton.png").resize(250, 250);
    /////Button
    private JLabel          startButton,scoreButton,exitButton;
    /////Player Name Part
    private JLabel          nametext = new JLabel("Player Name");
    private JTextField      nameinput = new JTextField("Please enter your name");
    /////Global variables
    private int frameWidth = 1366, frameHeight = 800;
    private int playerround=0;
    private String          playername;
    private ArrayList<Score> list       =   new ArrayList<Score>();
    private ArrayList<JLabel> namelist  =   new ArrayList<JLabel>();
    private ArrayList<JLabel> scorelist =   new ArrayList<JLabel>();
    
    File file = new File("list.txt");
    
    private MySoundEffect   themeSound;
    
    public Main(){

        setTitle("Mainmenu");
        setBounds(0, 0, frameWidth, frameHeight);
        setResizable(false);
        setVisible(true);
        setDefaultCloseOperation( WindowConstants.EXIT_ON_CLOSE );
        
        themeSound = new MySoundEffect("resources/BGSound_1.wav");
        themeSound.playLoop();
        
        /////Name Part
        nametext.setBounds(940, 125, 225, 50);
        nametext.setFont(new Font("Aerial" , Font.BOLD , 36));
        nametext.setForeground(Color.yellow);
        nameinput.setBounds(900, 200, 300, 50);
        nameinput.setFont(new Font("Aerial" , Font.BOLD , 25));
        nameinput.addMouseListener(new MouseAdapter(){
            public void mouseClicked(MouseEvent e)
            {
                nameinput.setText("");
            }
        });
        
        //namedialog.setBounds(500, 350, 300, 150);
        //namedialog.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        //namedialog.setVisible(false);
        /////Start Button
        startButton = new JLabel(startButtonImg);
        startButton.setBounds(900,250,300,200);
        //startButton.setOpaque(true);
        startButton.addMouseListener(new MouseListener(){
            public void mouseClicked(MouseEvent e)
            {
                playername = nameinput.getText();
                if(playername == null || playername.trim().isEmpty() || playername.compareTo​("Please enter your name")==0)
                {
                    JOptionPane nameerror = new JOptionPane ( );
                    nameerror.setMessageType ( JOptionPane.ERROR_MESSAGE );
                    nameerror.setMessage ("Please enter your name.");
                    JDialog namedialog = nameerror.createDialog ( null, "Name Error" );
                    namedialog.setVisible(true);
                }
                else
                {
                    //send playername to score system
                    list.add(new Score(0,playername));
                    themeSound.stop();
                    setVisible(false);
                    new NewGame();
                }
            }

            public void mousePressed(MouseEvent e) { }
            
            public void mouseReleased(MouseEvent e) { }

            public void mouseEntered(MouseEvent e)
            {
                startButton.setIcon(startFadeButtonImg);
            }

            public void mouseExited(MouseEvent e)
            {
                startButton.setIcon(startButtonImg);
            }
        });
        /////Score Button
        scoreButton = new JLabel(scoreButtonImg);
        scoreButton.setBounds(900,400,300,200);
        //scoreButton.setOpaque(true);
        scoreButton.addMouseListener(new MouseListener(){
            public void mouseClicked(MouseEvent e)
            {
                new Scoreboard();
            }

            public void mousePressed(MouseEvent e) { }
            
            public void mouseReleased(MouseEvent e) { }

            public void mouseEntered(MouseEvent e)
            {
                scoreButton.setIcon(scoreFadeButtonImg);
            }

            public void mouseExited(MouseEvent e)
            {
                scoreButton.setIcon(scoreButtonImg);
            }
        });
        /////Exit Button
        exitButton = new JLabel(exitButtonImg);
        exitButton.setBounds(900,550,300,200);
        //exitButton.setOpaque(true);
        exitButton.addMouseListener(new MouseListener(){
            public void mouseClicked(MouseEvent e)
            {
                System.exit(0);
            }

            public void mousePressed(MouseEvent e) { }
            
            public void mouseReleased(MouseEvent e) { }

            public void mouseEntered(MouseEvent e)
            {
                exitButton.setIcon(exitFadeButtonImg);
            }

            public void mouseExited(MouseEvent e)
            {
                exitButton.setIcon(exitButtonImg);
            }
        });
        
        /////Grouping Button
        mainmenu = new JLabel(menuBGImg);
        mainmenu.setLayout(null);
        //mainmenu.add();
        mainmenu.add(startButton);
        mainmenu.add(scoreButton);
        mainmenu.add(exitButton);
        /////Menu Icon
        menuIcon = new JLabel(menuIconImg);
        menuIcon.setLayout(null);
        menuIcon.setBounds(150,100,600,600);
        //menuIcon.setOpaque(true);
        /////Add to contentpane
        mainpane = (JPanel)getContentPane();
	mainpane.setLayout( new BorderLayout() );
        mainpane.add(nametext, BorderLayout.CENTER);
        mainpane.add(nameinput, BorderLayout.CENTER);
        mainpane.add(menuIcon, BorderLayout.CENTER);
        mainpane.add(mainmenu, BorderLayout.CENTER);
        validate();
    }
    
    class NewGame extends JFrame    {
    
        private JPanel             contentpane;
        private JLabel             drawpane;
        private JLabel             scoreover,scoreover2;
        private JTextField         scoreText;
        private JLabel             BGLabel;
        private JLabel             CrossHair,hitArea;
        private JLabel             HPBar,shieldBar,HP,HurtFX,firefx,alienDeadFX,alienAttackFX,alienShotFX,BoomFX,GameOver ;
        private JLabel             Hand,GrenadeLabel,GrenadeButton;
        private JLabel[]           AlienLabel = new JLabel[10];  
        private JFrame             menubar,InventoryFrame;
        private JToggleButton []   tb;
        private ButtonGroup        bgroup;
        private MyImageIcon        backgroundImg, CrossHairImg, HPBarImg,shieldImg,HandImg,hitAreaImg,GameOverImg,GrenadeButtonImg,
                                   AlienImg,AlienAtkImg,HPImg,HurtImg,firefxImg,alienDeadImg,shotImg,GrenadeImg,BoomImg;
        private MySoundEffect      fireSound, shellfallSound, shieldGainSound, shieldDownSound,BoomSound,
                                   AlienSound,ManDown,AlienDeadSFX,AlienAttackSFX,themeSound;
        

        public double PlayerHP = 1000;         //
        public double PlayerShield = 0;        //
        public int PlayerDmg = 20;              //
        public int GrenadeDamage = 0;         //
        public int score = 0;                   //
        public boolean isGameRunning = true;   //
        public int AlienDmg = 5;
        public int gearSelection = 1;

        private int frameWidth = 1366, frameHeight = 800;
        private int mouseX=0,mouseY=0;
        private boolean onMoveThread = false;      //
        private int BGCurX = -683,BGCurY = 0;    //-683
        private int BGWidth = 2732, BGHeight = 768;
        private int AlienWidth = 182,AlienHeight = 324;
        private int GrenadeWidth = 100,GrenadeHeight = 75;

        private int aliensMoveX;                                    //
        private int shieldX=0,shieldWidth=0,shieldWidthConst=0;     //
        private int movementSpeed = 3;                              //
        private int[] AvailableAlien = {1,1,1,1,1,1,1,1,1};
        private int SpawnDelay = 3000;
        private boolean gunFired = false;
        private boolean grenadeTrigger = false;                                     //////////ADD Grenade Trigger
        private boolean grenadeThrow = false;
        private int ratioY = frameHeight/8;
        public boolean isArmorActive = false, isBootActive = false, isGrenadeActive = false, isBulletActive = false;
        public boolean SpawnRateByTime = false, AlienDmgByTime = false;
        public boolean isDay = true, isEvening = false, isNight = false;
        public boolean isGrenadeAvailable = true;

        public NewGame(){
            setTitle("MainClass");
            setBounds(0, 0, frameWidth, frameHeight);
            setResizable(false);
            setVisible(true);
            setDefaultCloseOperation( WindowConstants.DO_NOTHING_ON_CLOSE );

            addWindowListener( new WindowListener(){

                public void windowOpened(WindowEvent e) {}

                public void windowClosing(WindowEvent e) {
                    
                    if(isGameRunning){
                        int confirm = JOptionPane.showConfirmDialog(new JFrame(), "Are you sure? If you exit now, the unsaved progress will be lost.", "EXIT",
                                          JOptionPane.YES_NO_OPTION );
                        if(confirm == JOptionPane.YES_OPTION ) {
                            dispose();
                            System.exit(0);
                        }
                    }else{
                        
                        int confirm = JOptionPane.showConfirmDialog(new JFrame(), "Would you like to try again?", "",
                                          JOptionPane.YES_NO_OPTION );
                        if(confirm == JOptionPane.YES_OPTION ) {
                            int i = 0;
                            while(i<9){
                                drawpane.remove(AlienLabel[i]);
                                i++;
                            }
                            themeSound.stop();
                            dispose();
                            new Main();
                        }
                        else{
                            dispose();
                            System.exit(0);
                        }
                        
                    }
                    
                }

                public void windowClosed(WindowEvent e) {}

                public void windowIconified(WindowEvent e) {}

                public void windowDeiconified(WindowEvent e) {}

                public void windowActivated(WindowEvent e) {}

                public void windowDeactivated(WindowEvent e) {}

            });

            addMouseMotionListener(new MouseMotionListener(){

                public void mouseDragged(MouseEvent e) {
                    mouseX = (int)MouseInfo.getPointerInfo().getLocation().getX();
                    mouseY = (int)MouseInfo.getPointerInfo().getLocation().getY();
                    if((mouseX < 100 || mouseX > frameWidth - 100)&& !onMoveThread) {
                        onMoveThread = true;
                        moveBGThread();
                        drawpane.repaint();
                    }
                    CrossHair.setLocation(mouseX-80,mouseY-113);
                    hitArea.setLocation(mouseX-20,mouseY-43);
                    if(mouseY > 296 && mouseY< 430){    Hand.setLocation((mouseX*3)/2-130 - mouseX*2/6,(mouseY*3)/2-163);
                    }else if(mouseY <= 296){            Hand.setLocation((mouseX*3)/2-130 - mouseX*2/6,(296*3)/2-163);
                    }else if(mouseY >= 430){            Hand.setLocation((mouseX*3)/2-130 - mouseX*2/6,(430*3)/2-163);  }
                    repaint();

                    try {TimeUnit.SECONDS.sleep(1/2);} 
                    catch (InterruptedException ex) {Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);}
                }

                public void mouseMoved(MouseEvent e) {
                    mouseX = (int)MouseInfo.getPointerInfo().getLocation().getX();
                    mouseY = (int)MouseInfo.getPointerInfo().getLocation().getY();
                    if((mouseX < 100 || mouseX > frameWidth - 100)&& !onMoveThread) {
                        onMoveThread = true;
                        moveBGThread();
                        drawpane.repaint();
                    }
                    if(!grenadeTrigger) CrossHair.setLocation(mouseX-80,mouseY-113);
                    else{
                        if(mouseY > 230){
                            GrenadeLabel.setLocation(mouseX-(((mouseY/ratioY)*(GrenadeWidth))/2) , mouseY-(((mouseY/ratioY)*(GrenadeHeight))*3/4));
                            GrenadeLabel.setIcon(new MyImageIcon("resources/grenadefield.png").resize((mouseY/ratioY)*(GrenadeWidth) , (mouseY/ratioY)*(GrenadeHeight)));
                            GrenadeLabel.resize((mouseY/ratioY)*(GrenadeWidth) , (mouseY/ratioY)*(GrenadeHeight));
                        }else{
                            GrenadeLabel.setLocation(mouseX-(((230/ratioY)*(GrenadeWidth))/2) , 230-(((230/ratioY)*(GrenadeHeight))*3/4));
                            GrenadeLabel.setIcon(new MyImageIcon("resources/grenadefield.png").resize((230/ratioY)*(GrenadeWidth) , (230/ratioY)*(GrenadeHeight)));
                            GrenadeLabel.resize((230/ratioY)*(GrenadeWidth) , (230/ratioY)*(GrenadeHeight));
                        }
                    }

                    hitArea.setLocation(mouseX-20,mouseY-43);

                    if(mouseY > 296 && mouseY< 430){    Hand.setLocation((mouseX*3)/2-130 - mouseX*2/6,(mouseY*3)/2-163);
                                                        firefx.setLocation(((mouseX*3)/2-125 - mouseX*2/6)-120,((mouseY*3)/2-163)-75);

                    }else if(mouseY <= 296){            Hand.setLocation((mouseX*3)/2-130 - mouseX*2/6,(296*3)/2-163);
                                                        firefx.setLocation(((mouseX*3)/2-125 - mouseX*2/6)-120,((296*3)/2-163)-75);

                    }else if(mouseY >= 430){            Hand.setLocation((mouseX*3)/2-130 - mouseX*2/6,(430*3)/2-163);  
                                                        firefx.setLocation(((mouseX*3)/2-125 - mouseX*2/6)-120,((430*3)/2-163)-75);
                    }
                    repaint();

                    try {TimeUnit.SECONDS.sleep(1/2);} 
                    catch (InterruptedException ex) {Logger.getLogger(Main
                            .class.getName()).log(Level.SEVERE, null, ex);}
                }

            });

            addMouseListener(new MouseListener(){

                public void mouseClicked(MouseEvent e) {
                    //System.out.println("Trigger pressed");
                    if(!grenadeTrigger) {   gunFireThread();    }
                    else                {   if(isGrenadeAvailable)   grenadeThrowThread();
                                            else                     JOptionPane.showMessageDialog(new JFrame(), "Your grenade launcher is cooling down!", "ALERT",
                                                                    JOptionPane.ERROR_MESSAGE );}
                }

                public void mousePressed(MouseEvent e) {
                    /*System.out.println("X : " + mouseX);
                    System.out.println("Y : " + mouseY);
                    System.out.println("BANG!!!");*/
                }

                public void mouseReleased(MouseEvent e) {
                    //System.out.println("Trigger released");
                }

                public void mouseEntered(MouseEvent e) {
                    System.out.println("Mouse - in");
                    onMoveThread = true;
                }

                public void mouseExited(MouseEvent e) {
                    System.out.println("Mouse - out ");
                    onMoveThread = false;
                    //moveBGThread();
                }

            });

            addKeyListener(new KeyListener(){

                public void keyTyped(KeyEvent e) {}

                public void keyPressed(KeyEvent e) {
                    if(e.getKeyCode() == KeyEvent.VK_E) {
                        Random r = new Random();
                        int n = r.nextInt(9);
                        moveAlienThread(n);
                    }
                    if(e.getKeyCode() == KeyEvent.VK_G) {
                        if(isGrenadeActive) swapGrenade();
                        else                JOptionPane.showMessageDialog(new JFrame(), "You have got no grenades.", "ALERT",
                                          JOptionPane.ERROR_MESSAGE );
                    }
                    
                    if(e.getKeyCode() == KeyEvent.VK_K) PlayerHP = 0;
                }

                public void keyReleased(KeyEvent e) {}

            });

            contentpane = (JPanel)getContentPane();
            contentpane.setLayout( new BorderLayout() ); 
            AddComponents();
        }

        public void AddComponents()
        {
            backgroundImg = new MyImageIcon("resources/BG.jpg").resize(2732, 768);
            CrossHairImg = new MyImageIcon("resources/crosshair.png").resize(150, 150);
            hitAreaImg = new MyImageIcon("resources/hitarea.png").resize(30, 30);
            shieldImg = new MyImageIcon("resources/shield.png").resize(1366, 768);
            HPBarImg = new MyImageIcon("resources/HPBar.png").resize(1366, 768);
            HPImg = new MyImageIcon("resources/HP.png").resize(1366, 768);
            HandImg = new MyImageIcon("resources/Hand.png").resize(512, 512);
            AlienImg = new MyImageIcon("resources/alien1.png").resize(AlienWidth/4, AlienHeight/4);
            AlienAtkImg = new MyImageIcon("resources/alienAttack.png").resize(AlienWidth/4, AlienHeight/4);
            HurtImg = new MyImageIcon("resources/hurt.png").resize(1366, 768);
            firefxImg = new MyImageIcon("resources/firefx.png").resize(256, 256);
            alienDeadImg = new MyImageIcon("resources/alienDead.png").resize(AlienWidth/4, AlienHeight/4);
            shotImg = new MyImageIcon("resources/shot.png").resize(AlienWidth/4, AlienHeight/4);
            GrenadeImg = new MyImageIcon("resources/grenadefield.png").resize(GrenadeWidth,GrenadeHeight); 
            GrenadeButtonImg = new MyImageIcon("resources/grenadeButton.png").resize(1366, 768); 
            BoomImg = new MyImageIcon("resources/BoomFX.png").resize(GrenadeWidth,GrenadeHeight); 
            GameOverImg = new MyImageIcon("resources/GameOver.png").resize(1366, 768);

            shellfallSound   = new MySoundEffect("resources/shellfallfx.wav");
            shieldGainSound = new MySoundEffect("resources/shieldGain.wav");
            shieldDownSound = new MySoundEffect("resources/shieldDown.wav");
            BoomSound = new MySoundEffect("resources/Boom.wav");
            ManDown = new MySoundEffect("resources/PlayerDead.wav");
            AlienSound = new MySoundEffect("resources/AlienSound.wav");
            themeSound = new MySoundEffect("resources/BGSound_1.wav");
            
            themeSound.playLoop();

            drawpane = new JLabel();
            drawpane.setLayout(null);

            scoreover =new JLabel(); 
            scoreover2 =new JLabel();
          
            scoreover2.setForeground(Color.white);
            scoreover.setForeground(Color.white);
            
            scoreover2.setBounds(550,420,1000,200);
            scoreover2.setFont(new Font("SanSerif", Font.BOLD, 36));
            scoreover2.setVisible(false);
            scoreover.setBounds(550,320,1000,200);
            scoreover.setFont(new Font("SanSerif", Font.BOLD, 36));
            scoreover.setVisible(false);
           
            GameOver = new JLabel(GameOverImg);
            GameOver.setBounds(0,0,1366,768);
            GameOver.setVisible(false);
            
            drawpane.add(scoreover);
            drawpane.add(scoreover2);
            drawpane.add(GameOver);
           
            HurtFX = new JLabel(HurtImg);
            HurtFX.setBounds(0, 0, 1366, 768);
            HurtFX.setVisible(false);
            drawpane.add(HurtFX);

            alienShotFX = new JLabel(shotImg);
            alienShotFX.setBounds(0, 0, AlienWidth/4, AlienHeight/4);
            alienShotFX.setVisible(false);
            drawpane.add(alienShotFX);

            alienDeadFX = new JLabel(alienDeadImg);
            alienDeadFX.setBounds(0, 0, AlienWidth/4, AlienHeight/4);
            alienDeadFX.setVisible(false);
            drawpane.add(alienDeadFX);
            
            alienAttackFX = new JLabel(AlienAtkImg);
            alienAttackFX.setBounds(0, 0, 0, 0);
            alienAttackFX.setVisible(false);
            drawpane.add(alienAttackFX);

            HP = new JLabel(HPImg);
            HP.setBounds(468, 0, 430, 768);
            drawpane.add(HP);

            shieldBar = new JLabel(shieldImg);
            shieldBar.setBounds(0, 0, 0, 0);
            drawpane.add(shieldBar);

            HPBar = new JLabel(HPBarImg);
            HPBar.setBounds(0, 0, 1366, 768);
            drawpane.add(HPBar);
            
            GrenadeButton = new JLabel(GrenadeButtonImg);
            GrenadeButton.setBounds(0, 0, 1366, 768);
            drawpane.add(GrenadeButton);

            Hand = new JLabel(HandImg);
            Hand.setBounds(750, 350, 512, 512);
            drawpane.add(Hand);

            firefx = new JLabel(firefxImg);
            firefx.setBounds(750, 350, 256, 256);
            drawpane.add(firefx);
            firefx.setVisible(false);

            CrossHair = new JLabel(CrossHairImg);
            CrossHair.setBounds(630, 320, 150, 150);
            drawpane.add(CrossHair);

            hitArea = new JLabel(hitAreaImg);
            hitArea.setBounds(747, 416, 30, 30);
            drawpane.add(hitArea);

            BoomFX = new JLabel(BoomImg);
            BoomFX.setBounds(0, 0, GrenadeWidth,GrenadeHeight);
            drawpane.add(BoomFX); 
            BoomFX.setVisible(false);

            menubar = new menubar(PlayerHP);

            int i=0;
            while(i<=8){
                AlienLabel[i] = new JLabel(AlienImg);
                if(i>=0 && i<=2)            AlienLabel[i].setBounds(600+(i*40), 50, 182, 324);
                else if(i>=3 && i<=5)       AlienLabel[i].setBounds(-224+((i-3)*40), 50, 182, 324);
                else if(i>=6 && i<=8)       AlienLabel[i].setBounds(1479+((i-6)*40), 50, 182, 324);
                AlienLabel[i].setVisible(false);
                drawpane.add(AlienLabel[i]);
                i++;
            }

            GrenadeLabel = new JLabel(GrenadeImg);                                  
            GrenadeLabel.setBounds(0, 0, GrenadeWidth,GrenadeHeight);               
            drawpane.add(GrenadeLabel);                                             
            GrenadeLabel.setVisible(false);

            BGLabel = new JLabel(backgroundImg);
            BGLabel.setBounds(BGCurX, BGCurY, BGWidth, BGHeight);
            drawpane.add(BGLabel);

            contentpane.add(drawpane, BorderLayout.CENTER);  

            validate();
            AlienSpawnThread();
            EventThread();
        }
        
        public void EventThread(){
            Thread EventThread = new Thread(){
                int sec = 0;
                int GCooldown = 0;
                public void run(){
                    
                    while(isGameRunning){
                        
                        if(PlayerHP <= 0){
                            isGameRunning = false;
                            GameOver.setVisible(true);
                            
                            scoreover.setText("Agent : " + list.get(list. size()-1).getName());
                            scoreover2.setText("  score : " + Integer.toString(score));
                            
                            try{
                                PrintWriter out = new PrintWriter(new FileWriter(file, true));
                                out.write(playername+","+score+"\n");
                                out.close();
                            }
                            catch(IOException e){ System.out.println(e);} 
                            
                            scoreover.setVisible(true);
                            scoreover2.setVisible(true);
                            
                            menubar.setVisible(false);
                            ManDown.playOnce();
                            AlienSound.playOnce();
                        }
                        
                        if(sec%20==0){
                            if(isDay && sec != 0){
                                isDay = false;
                                BGLabel.setIcon(new MyImageIcon("resources/BG2.jpg").resize(2732, 768));
                                isEvening = true;
                            }
                            else if(isEvening){
                                isEvening = false;
                                BGLabel.setIcon(new MyImageIcon("resources/BG3.jpg").resize(2732, 768));
                                isNight = true;
                            }
                            else if(isNight){
                                isNight = false;
                                BGLabel.setIcon(new MyImageIcon("resources/BG.jpg").resize(2732, 768));
                                isDay = true;
                            }
                        }
                        
                        if(isNight) RandomBlink();
                        
                        if(SpawnRateByTime)                 SpawnDelay -= 10;

                        if(AlienDmgByTime && sec%2==0 )     AlienDmg += 1;
                        
                        if(!isGrenadeAvailable){
                            if(GCooldown >= 3){
                                isGrenadeAvailable = true;
                                GCooldown = 0;
                            }
                            else    GCooldown++;
                        }

                        try { Thread.sleep(1000); } 
                        catch (InterruptedException e) { e.printStackTrace(); }
                        sec++;
                        //System.out.println(sec + " seconds");
                    }
                    
                }
                
                public void RandomBlink(){
                    Random r = new Random();
                    int x = r.nextInt(2);
                    switch(x){
                        case 0 -> { BGLabel.setIcon(new MyImageIcon("resources/BG3.jpg").resize(2732, 768));    }
                        case 1 -> { BGLabel.setIcon(new MyImageIcon("resources/BG4.jpg").resize(2732, 768));    }
                    }
                }
                
            };
            EventThread.start();
        }

        public void gunFireThread(){
            Thread fireThread = new Thread(){
              public void run(){
                  gunFired = true;
                  firefx.setVisible(true);
                  fireSound   = new MySoundEffect("resources/gunfx.wav");
                  fireSound.playOnce();
                  try { Thread.sleep(50); } 
                  catch (InterruptedException e) { e.printStackTrace(); }
                  firefx.setVisible(false);
                  shellfallSound.playOnce();
                  gunFired = false;
              }
            };
            fireThread.start();
        }

        public void grenadeThrowThread()
        {
            Thread throwThread = new Thread(){
                public void run(){
                    isGrenadeAvailable = false;
                    grenadeThrow = true;
                    if(mouseY > 240){
                        BoomFX.setLocation(mouseX-(((mouseY/ratioY)*(GrenadeWidth))/2) , mouseY-(((mouseY/ratioY)*(GrenadeHeight))*3/4));
                        switch(gearSelection){
                            case 1 -> {BoomFX.setIcon(new MyImageIcon("resources/BoomFX.png").resize((mouseY/ratioY)*(GrenadeWidth) , (mouseY/ratioY)*(GrenadeHeight)));}
                            case 2 -> {BoomFX.setIcon(new MyImageIcon("resources/BoomFX2.png").resize((mouseY/ratioY)*(GrenadeWidth) , (mouseY/ratioY)*(GrenadeHeight)));}
                            case 3 -> {BoomFX.setIcon(new MyImageIcon("resources/BoomFX3.png").resize((mouseY/ratioY)*(GrenadeWidth) , (mouseY/ratioY)*(GrenadeHeight)));}
                        }
                        BoomFX.resize((mouseY/ratioY)*(GrenadeWidth) , (mouseY/ratioY)*(GrenadeHeight));
                    }else{
                        BoomFX.setLocation(mouseX-(((240/ratioY)*(GrenadeWidth))/2) , 230-(((230/ratioY)*(GrenadeHeight))*3/4));
                        switch(gearSelection){
                            case 1 -> {BoomFX.setIcon(new MyImageIcon("resources/BoomFX.png").resize((240/ratioY)*(GrenadeWidth) , (240/ratioY)*(GrenadeHeight)));}
                            case 2 -> {BoomFX.setIcon(new MyImageIcon("resources/BoomFX2.png").resize((240/ratioY)*(GrenadeWidth) , (240/ratioY)*(GrenadeHeight)));}
                            case 3 -> {BoomFX.setIcon(new MyImageIcon("resources/BoomFX3.png").resize((240/ratioY)*(GrenadeWidth) , (240/ratioY)*(GrenadeHeight)));}
                        }
                        BoomFX.resize((230/ratioY)*(GrenadeWidth) , (230/ratioY)*(GrenadeHeight));
                    }
                    BoomFX.setVisible(true);
                    BoomSound.playOnce();
                    System.out.println("Throw Grenade!!!");
                    try { Thread.sleep(500); } 
                    catch (InterruptedException e) { e.printStackTrace(); }
                    System.out.println("BOOM!!!!!");
                    BoomFX.setVisible(false);
                    grenadeThrow = false;
                }
            };
            throwThread.start();
        }

        public void swapGrenade()
        {

            if(grenadeTrigger == false)
            {
                grenadeTrigger = true;
                GrenadeLabel.setVisible(true);
                CrossHair.setVisible(false);
            }
            else
            {
                grenadeTrigger = false;
                GrenadeLabel.setVisible(false);
                CrossHair.setVisible(true);
            }
        }

        public void AlienSpawnThread(){
            Thread SpawnThread = new Thread(){
                public void run(){
                    while(isGameRunning){
                        Random r = new Random();
                        int n = r.nextInt(9);
                        moveAlienThread(n);
                        try { Thread.sleep(SpawnDelay); } 
                        catch (InterruptedException e) { e.printStackTrace(); }
                    }
                }
            };

            SpawnThread.start();
        }

        public void moveAlienThread(int n){
            Thread AlienThread = new Thread(){
                private int AlienX,AlienY,oldX,oldY;
                private int AlienHP = 100;
                public void run(){
                    int i=0;
                    if(AvailableAlien[n] == 1){
                        AvailableAlien[n] = 0;
                        oldX = AlienX = AlienLabel[n].getLocation().x;
                        oldY = AlienY = AlienLabel[n].getLocation().y;
                        AlienLabel[n].setLocation(AlienX+aliensMoveX,AlienY);
                        AlienLabel[n].setVisible(true);
                        while(AlienY<=200){
                            if(isDay)           AlienLabel[n].setIcon(new MyImageIcon("resources/alien1.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                            else if(isEvening)  AlienLabel[n].setIcon(new MyImageIcon("resources/alienEvening.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                            else if(isNight)    AlienLabel[n].setIcon(new MyImageIcon("resources/alienNight.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                            AlienLabel[n].resize(AlienWidth/2+(i*632/100), AlienHeight/2+(i*1125/100));
                            AlienY += 5;
                            switch(n){
                                case 0 -> AlienX -= 7;         //ok
                                case 1 -> AlienX -= 334/100;   //ok
                                case 2 -> AlienX += 334/100;   //ok
                                case 3 -> AlienX -= 7;         //ok 
                                case 4 -> AlienX += 260/100;   //ok
                                case 5 -> AlienX += 857/100;   //ok
                                case 6 -> AlienX -= 1257/100;  //ok
                                case 7 -> AlienX -= 700/100;   //ok
                                case 8 -> AlienX += 250/100;   //ok
                            }
                            AlienLabel[n].setLocation(AlienX+aliensMoveX,AlienY);
                            if(gunFired && hitArea.getBounds().intersects(AlienLabel[n].getBounds())){
                                Random r = new Random();
                                int rx = r.nextInt(50);
                                int ry = r.nextInt(80);
                                alienShotFX.setIcon(new MyImageIcon("resources/shot.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                                alienShotFX.resize(AlienWidth/2+(i*632/100), AlienHeight/2+(i*1125/100));
                                alienShotFX.setLocation(AlienX+aliensMoveX+rx,AlienY+ry);
                                AlienHP -= PlayerDmg;
                                alienShotFX.setVisible(true);
                                try { Thread.sleep(50); } 
                                catch (InterruptedException e) { e.printStackTrace(); }
                                alienShotFX.setVisible(false);
                            }
                            if(grenadeThrow && AlienLabel[n].getBounds().intersects(GrenadeLabel.getBounds()))  AlienHP -= GrenadeDamage;
                            if(AlienHP <= 0){
                                updateScore();
                                alienDeadFX.setIcon(new MyImageIcon("resources/alienDead.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                                alienDeadFX.resize(AlienWidth/2+(i*632/100), AlienHeight/2+(i*1125/100));
                                alienDeadFX.setLocation(AlienX+aliensMoveX,AlienY);
                                alienDeadFX.setVisible(true);
                                try { Thread.sleep(500); } 
                                catch (InterruptedException e) { e.printStackTrace(); }
                                alienDeadFX.setVisible(false);
                                break;
                            }
                            //System.out.println(i++);
                            i++;
                            try { Thread.sleep(50); } 
                            catch (InterruptedException e) { e.printStackTrace(); }
                        }
                        int j = 0;
                        while(AlienHP > 0 && isGameRunning){

                            Random r = new Random();
                            int m = r.nextInt(2);

                            if(m==1 && j/60 >= 1){
                                AlienAttack(AlienDmg,i,AlienX,AlienY);
                                j=j%60;
                            }
                            
                            if(isDay)           AlienLabel[n].setIcon(new MyImageIcon("resources/alien1.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                            else if(isEvening)  AlienLabel[n].setIcon(new MyImageIcon("resources/alienEvening.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                            else if(isNight)    AlienLabel[n].setIcon(new MyImageIcon("resources/alienNight.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));

                            AlienLabel[n].setLocation(AlienX+aliensMoveX,AlienY);
                            if(gunFired && hitArea.getBounds().intersects(AlienLabel[n].getBounds())){
                                 r = new Random();
                                int rx = r.nextInt(50);
                                int ry = r.nextInt(80);
                                alienShotFX.setIcon(new MyImageIcon("resources/shot.png").resize(AlienWidth/2+(i*275/100)+10, AlienHeight/2+(i*5)+10));
                                alienShotFX.resize(AlienWidth/2+(i*632/100)+10, AlienHeight/2+(i*1125/100)+10);
                                alienShotFX.setLocation(AlienX+aliensMoveX+rx,AlienY+ry);
                                AlienHP -= PlayerDmg;
                                alienShotFX.setVisible(true);
                                try { Thread.sleep(50); } 
                                catch (InterruptedException e) { e.printStackTrace(); }
                                alienShotFX.setVisible(false);
                            }
                            else if(grenadeThrow && AlienLabel[n].getBounds().intersects(GrenadeLabel.getBounds())) AlienHP -= GrenadeDamage;
                            try { Thread.sleep(50); } 
                            catch (InterruptedException e) { e.printStackTrace(); }
                            j++;
                        }
                        
                        if(isGameRunning)   updateScore();
                        
                        AlienDeadSFX   = new MySoundEffect("resources/AlienDeadSFX.wav");
                        AlienDeadSFX.playOnce();
                        
                        alienDeadFX.setIcon(new MyImageIcon("resources/alienDead.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                        alienDeadFX.resize(AlienWidth/2+(i*632/100), AlienHeight/2+(i*1125/100));
                        alienDeadFX.setLocation(AlienX+aliensMoveX,AlienY);
                        alienDeadFX.setVisible(true);
                        try { Thread.sleep(500); } 
                        catch (InterruptedException e) { e.printStackTrace(); }
                        alienDeadFX.setVisible(false);

                        AlienLabel[n].setVisible(false);
                        AlienLabel[n].setLocation(oldX,oldY);
                        AvailableAlien[n] = 1;
                    }
                    //else    System.out.println("Alien number " + n + " is not available right now.");

                }
                
                public void setDead(){  AlienHP = 0;    }
                
            };
            AlienThread.start();
        }

        synchronized public void AlienAttack(int dmg,int i, int AlienX,int AlienY){
            Thread ReduceHP = new Thread(){

                public void run(){

                    if(PlayerShield > 0){
                        PlayerShield -= dmg;
                        System.out.println("Ahhh! (-" + dmg + ")");
                        System.out.println("Shield = " + PlayerShield + "(" + shieldWidthConst + ")");
                        if(PlayerShield <= 0)   {
                            shieldBar.setBounds(0,0,0,0);
                            shieldDownSound.playOnce();
                        }
                    }
                    else{
                        PlayerHP -= dmg;
                        System.out.println("Ouch! (-" + dmg + ")");
                        System.out.println("HP = " + PlayerHP);
                    }

                    if(PlayerHP <= 0)               HP.setBounds(649, 0,  68, 768);
                    else if(PlayerHP <= 62.5)       HP.setBounds(638, 0,  90, 768);
                    else if(PlayerHP <= 125)        HP.setBounds(627, 0, 112, 768);
                    else if(PlayerHP <= 187.5)      HP.setBounds(616, 0, 134, 768);
                    else if(PlayerHP <= 250)        HP.setBounds(605, 0, 156, 768);
                    else if(PlayerHP <= 312.5)      HP.setBounds(594, 0, 178, 768);
                    else if(PlayerHP <= 375)        HP.setBounds(583, 0, 200, 768);
                    else if(PlayerHP <= 437.5)      HP.setBounds(572, 0, 222, 768);
                    else if(PlayerHP <= 562.5)      HP.setBounds(550, 0, 266, 768);
                    else if(PlayerHP <= 625)        HP.setBounds(540, 0, 286, 768);
                    else if(PlayerHP <= 687.5)      HP.setBounds(528, 0, 310, 768);
                    else if(PlayerHP <= 750)        HP.setBounds(518, 0, 330, 768);
                    else if(PlayerHP <= 812.5)      HP.setBounds(506, 0, 354, 768);
                    else if(PlayerHP <= 875)        HP.setBounds(496, 0, 374, 768);
                    else if(PlayerHP <= 937.5)      HP.setBounds(486, 0, 394, 768);
                    
                    if(isDay)           alienAttackFX.setIcon(new MyImageIcon("resources/alienAttack.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                    else if(isEvening)  alienAttackFX.setIcon(new MyImageIcon("resources/alienAttackEvening.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                    else if(isNight)    alienAttackFX.setIcon(new MyImageIcon("resources/alienAttackNight.png").resize(AlienWidth/2+(i*275/100), AlienHeight/2+(i*5)));
                    
                    AlienAttackSFX = new MySoundEffect("resources/AlienAttack.wav");
                    AlienAttackSFX.playOnce();
                    
                    alienAttackFX.resize(AlienWidth/2+(i*632/100), AlienHeight/2+(i*1125/100));
                    alienAttackFX.setLocation(AlienX+aliensMoveX,AlienY);
                    alienAttackFX.setVisible(true);
                    HurtFX.setVisible(true);
                    
                    try { Thread.sleep(200); } 
                    catch (InterruptedException e) { e.printStackTrace(); }
                    
                    HurtFX.setVisible(false);
                    alienAttackFX.setVisible(false);
                }

            };
            ReduceHP.start();

        }

        synchronized void updateScore(){
            score+=100;
            scoreText.setText(String.valueOf(score));
        }

        public void moveBGThread()
        {
            Thread BGThread = new Thread() {
                public void run()
                {
                    while((mouseX < 100 || mouseX > frameWidth - 100)&& onMoveThread){
                        BGLabel.setLocation(BGCurX, BGCurY);
                        if(mouseX <= 100 && BGCurX < 0){
                            BGCurX+=movementSpeed;
                            aliensMoveX += movementSpeed;
                            //System.out.println("moving left CurX = " + BGCurX);
                        }
                        else if(mouseX >=frameWidth-100 && BGCurX > -1375){
                            BGCurX-=movementSpeed;
                            aliensMoveX -= movementSpeed;
                            //System.out.println("moving right CurX = " + BGCurX);
                        }
                        repaint();
                        try { Thread.sleep(5); } 
                        catch (InterruptedException e) { e.printStackTrace(); }
                    }
                    onMoveThread = false;
                } // end run
            }; // end thread creation
            BGThread.start();
        }

        class menubar extends JFrame {

        private JPanel      contentpane;
        private JFrame      InventoryFrame = null;
        private JButton     InventoryButton;
        private JLabel      drawpane;
        private MyImageIcon        backgroundImg ;
        private boolean     isInvVisible = false;

            public menubar(double HP){
                setType(javax.swing.JFrame.Type.UTILITY);
                setAlwaysOnTop(true);
                setBounds(1180, 580, 100, 200);
                setResizable(false);
                setVisible(true);
                setDefaultCloseOperation( WindowConstants.DO_NOTHING_ON_CLOSE );

                contentpane = (JPanel)getContentPane();
                contentpane.setLayout( new BorderLayout() ); 
                AddComponents();
            }

            public void AddComponents(){

                backgroundImg = new MyImageIcon("resources/menubarBG.png").resize(152, 163);

                JPanel control = new JPanel();
                control.setBounds(7, 8, 138, 150);
                control.setBackground(Color.decode("#24334b"));

                drawpane = new JLabel();
                drawpane.setIcon(backgroundImg);
                drawpane.setLayout(null);

                InventoryFrame = new Inventory();
                InventoryFrame.setVisible(false);

                InventoryButton = new JButton("Inventory");
                InventoryButton.addActionListener( new ActionListener(){
                    public void actionPerformed(ActionEvent e) {
                        if(!isInvVisible)  {
                            InventoryFrame.setVisible(true);
                            isInvVisible = true;
                        }else{
                            InventoryFrame.setVisible(false);
                            isInvVisible = false;
                        }
                    }
                });

                JLabel scoreLabel = new JLabel("  score");
                scoreLabel.setForeground(Color.white);

                control.add(scoreLabel);
                scoreText = new JTextField("0",5);
                scoreText.setEditable(false);
                control.add(scoreText);
                control.add(new JLabel("                     "));
                control.add(new JLabel("                     "));
                control.add(new JLabel("                     "));
                control.add(InventoryButton);

                contentpane.add(control,BorderLayout.CENTER);
                contentpane.add(drawpane,BorderLayout.CENTER);

                validate();

            }
        }

        class Inventory extends JFrame{

            private JLabel drawpane;
            private JPanel contentpane;
            private MyImageIcon backgroundImg;
            private JComboBox equipment1ComboBox,equipment2ComboBox,equipment3ComboBox,equipment4ComboBox;

            private MyImageIcon equipmentList1[] = {
                    new MyImageIcon("resources/armor1.png").resize(50, 50),
                    new MyImageIcon("resources/boots1.png").resize(50, 50),
                    new MyImageIcon("resources/bullet1.png").resize(50, 50),
                    new MyImageIcon("resources/grenade1.png").resize(50, 50),
                    new MyImageIcon("resources/blank.png").resize(50, 50)
                };
            private MyImageIcon equipmentList2[] = {
                    new MyImageIcon("resources/armor2.png").resize(50, 50),
                    new MyImageIcon("resources/boots2.png").resize(50, 50),
                    new MyImageIcon("resources/bullet2.png").resize(50, 50),
                    new MyImageIcon("resources/grenade2.png").resize(50, 50),
                    new MyImageIcon("resources/blank.png").resize(50, 50)
                };
            private MyImageIcon equipmentList3[] = {
                    new MyImageIcon("resources/armor3.png").resize(50, 50),
                    new MyImageIcon("resources/boots3.png").resize(50, 50),
                    new MyImageIcon("resources/bullet3.png").resize(50, 50),
                    new MyImageIcon("resources/grenade3.png").resize(50, 50),
                    new MyImageIcon("resources/blank.png").resize(50, 50)
                };
            private ComboBoxRenderar rendrar;
            private Integer n[] = {1,2,3,4,5};
            private String[] equipmentName = {"ARMOR","BOOTS","BULLET","GRENADE","UNEQUIP"};

            public Inventory(){

                setTitle("Inventory");
                setBounds(10, 40, 500, 500);
                setResizable(false);
                setVisible(true);
                setAlwaysOnTop(true);
                setDefaultCloseOperation( WindowConstants.DO_NOTHING_ON_CLOSE );

                addWindowListener(new WindowListener(){

                    public void windowOpened(WindowEvent e) {}

                    public void windowClosing(WindowEvent e) {}

                    public void windowClosed(WindowEvent e) {}

                    public void windowIconified(WindowEvent e) {}

                    public void windowDeiconified(WindowEvent e) {}

                    public void windowActivated(WindowEvent e) {}

                    public void windowDeactivated(WindowEvent e) {}

                });

                contentpane = (JPanel)getContentPane();
                contentpane.setLayout( new BorderLayout() ); 
                AddComponents();

            }

            public void AddComponents(){

                backgroundImg = new MyImageIcon("resources/inventory.png").resize(485, 485);

                JPanel equipment1 = new JPanel();
                equipment1.setBounds(45, 47, 120, 60);
                equipment1.setBackground(Color.decode("#577981"));

                JPanel equipment2 = new JPanel();
                equipment2.setBounds(45, 138, 120, 60);
                equipment2.setBackground(Color.decode("#577981"));

                JPanel equipment3 = new JPanel();
                equipment3.setBounds(319, 47, 120, 60);
                equipment3.setBackground(Color.decode("#577981"));

                JPanel equipment4 = new JPanel();
                equipment4.setBounds(319, 138, 120, 60);
                equipment4.setBackground(Color.decode("#577981"));

                rendrar = new ComboBoxRenderar();

                equipment1ComboBox = new JComboBox(n);
                equipment1ComboBox.setSelectedIndex(4);
                equipment1ComboBox.setRenderer(rendrar);
                equipment1ComboBox.addItemListener( new ItemListener() {
                    public void itemStateChanged( ItemEvent e ){
                        setComboBox(e,equipment1ComboBox);
                    }
                });

                equipment1.add(equipment1ComboBox);

                equipment2ComboBox = new JComboBox(n);
                equipment2ComboBox.setSelectedIndex(4);
                equipment2ComboBox.setRenderer(rendrar);
                equipment2ComboBox.addItemListener( new ItemListener() {
                    public void itemStateChanged( ItemEvent e ){
                        setComboBox(e,equipment2ComboBox);
                    }
                });

                equipment2.add(equipment2ComboBox);

                equipment3ComboBox = new JComboBox(n);
                equipment3ComboBox.setSelectedIndex(4);
                equipment3ComboBox.setRenderer(rendrar);
                equipment3ComboBox.addItemListener( new ItemListener() {
                    public void itemStateChanged( ItemEvent e ){
                        setComboBox(e,equipment3ComboBox);
                    }
                });

                equipment3.add(equipment3ComboBox);

                equipment4ComboBox = new JComboBox(n);
                equipment4ComboBox.setSelectedIndex(4);
                equipment4ComboBox.setRenderer(rendrar);
                equipment4ComboBox.addItemListener( new ItemListener() {
                    public void itemStateChanged( ItemEvent e ){
                        setComboBox(e,equipment4ComboBox);
                    }
                });

                equipment4.add(equipment4ComboBox);

                JPanel control = new JPanel();
                control.setBounds(35, 255, 415, 183);
                control.setBackground(Color.decode("#587a82"));

                tb = new JToggleButton[3];     
                tb[0] = new JRadioButton("  Low Grade Gear ");   //tb[0].setName("Left");
                tb[1] = new JRadioButton("Medium Grade Gear");  //tb[1].setName("Right"); 
                tb[2] = new JRadioButton(" High Grade Gear ");  //tb[2].setName("Right");
                tb[0].setSelected(true);
                bgroup = new ButtonGroup();
                bgroup.add(tb[0]);  bgroup.add(tb[1]);  bgroup.add(tb[2]);
                tb[0].addItemListener(new ItemListener ()
                {
                    public void itemStateChanged(ItemEvent e)
                    {
                        equipment1.remove(equipment1ComboBox);
                        equipment2.remove(equipment2ComboBox);
                        equipment3.remove(equipment3ComboBox);
                        equipment4.remove(equipment4ComboBox);

                        resetEquipment();
                        setRadioButton( e, 1);

                        equipment1.add(equipment1ComboBox);
                        equipment2.add(equipment2ComboBox);
                        equipment3.add(equipment3ComboBox);
                        equipment4.add(equipment4ComboBox);

                        repaint();
                    }
                });
                tb[1].addItemListener(new ItemListener ()
                {
                    public void itemStateChanged(ItemEvent e)
                    {
                        equipment1.remove(equipment1ComboBox);
                        equipment2.remove(equipment2ComboBox);
                        equipment3.remove(equipment3ComboBox);
                        equipment4.remove(equipment4ComboBox);

                        resetEquipment();
                        setRadioButton( e, 2);

                        equipment1.add(equipment1ComboBox);
                        equipment2.add(equipment2ComboBox);
                        equipment3.add(equipment3ComboBox);
                        equipment4.add(equipment4ComboBox);

                        repaint();
                    }
                });
                tb[2].addItemListener(new ItemListener ()
                {
                    public void itemStateChanged(ItemEvent e)
                    {
                        equipment1.remove(equipment1ComboBox);
                        equipment2.remove(equipment2ComboBox);
                        equipment3.remove(equipment3ComboBox);
                        equipment4.remove(equipment4ComboBox);

                        resetEquipment();
                        setRadioButton( e, 3);

                        equipment1.add(equipment1ComboBox);
                        equipment2.add(equipment2ComboBox);
                        equipment3.add(equipment3ComboBox);
                        equipment4.add(equipment4ComboBox);

                        repaint();
                    }
                });

                control.add(tb[0]);
                control.add(tb[1]);
                control.add(tb[2]);

                JLabel Label;
                Label = new JLabel("Armor [ +100 HP ]            Armor [ +200 HP ]           Armor [ +300 HP ]");
                Label.setForeground(Color.white);
                control.add(Label);
                Label = new JLabel("  Bullet [ 30 DMG ]       BULLET [ 40 DMG ]       BULLET [ +50 DMG ]");
                Label.setForeground(Color.white);
                control.add(Label);
                Label = new JLabel("Boots [ 5 speed ]            Boots [ 10 speed ]           Boots [ 15 speed ]");
                Label.setForeground(Color.white);
                control.add(Label);
                Label = new JLabel("                                                                              ");
                control.add(Label);

                JCheckBox checkbox1 ;
                checkbox1 = new JCheckBox("Increase Alien Spawn rate by time");
                checkbox1.addItemListener(new ItemListener(){
                    
                    public void itemStateChanged(ItemEvent e) {
                        if(e.getStateChange() == ItemEvent.SELECTED)            SpawnRateByTime = true;
                        else if(e.getStateChange() == ItemEvent.DESELECTED)     SpawnRateByTime = false;
                    }
                    
                });
                control.add(checkbox1);
                JCheckBox checkbox2 ;
                checkbox2 = new JCheckBox("Increase Alien attack damage by time");
                checkbox2.addItemListener(new ItemListener(){
                    
                    public void itemStateChanged(ItemEvent e) {
                        if(e.getStateChange() == ItemEvent.SELECTED)            AlienDmgByTime = true;
                        else if(e.getStateChange() == ItemEvent.DESELECTED)     AlienDmgByTime = false;
                    }
                    
                });
                control.add(checkbox2);

                drawpane = new JLabel();
                drawpane.setIcon(backgroundImg);
                drawpane.setLayout(null);

                contentpane.add(equipment1);  
                contentpane.add(equipment2);
                contentpane.add(equipment3);
                contentpane.add(equipment4);
                contentpane.add(control, BorderLayout.CENTER);  
                contentpane.add(drawpane, BorderLayout.CENTER);  

                validate();

            }

            public void setRadioButton(ItemEvent e, int selected){

                 if(e.getStateChange() == ItemEvent.SELECTED)
                {
                    gearSelection = selected;
                    rendrar = new ComboBoxRenderar();
                    equipment1ComboBox.setRenderer(rendrar);
                    equipment2ComboBox.setRenderer(rendrar);
                    equipment3ComboBox.setRenderer(rendrar);
                    equipment4ComboBox.setRenderer(rendrar);

                    equipment1ComboBox.setSelectedIndex(4);
                    equipment2ComboBox.setSelectedIndex(4);
                    equipment3ComboBox.setSelectedIndex(4);
                    equipment4ComboBox.setSelectedIndex(4);
                }   

            }

            public void setComboBox(ItemEvent e, JComboBox ComboBox){
                if(e.getStateChange() == ItemEvent.SELECTED){
                            switch((int)e.getItem()){
                                case 1 -> {
                                    if(!isArmorActive){
                                        isArmorActive = true;
                                        if(gearSelection == 1)       {PlayerShield = 100 ;  shieldX = 640; shieldWidthConst = shieldWidth =  86;}
                                        else if(gearSelection == 2)  {PlayerShield = 200 ;  shieldX = 597; shieldWidthConst = shieldWidth = 172;}
                                        else if(gearSelection == 3)  {PlayerShield = 300 ;  shieldX = 554; shieldWidthConst = shieldWidth = 258;}
                                        shieldBar.setBounds(shieldX, 0, shieldWidth, 768);
                                        shieldGainSound.playOnce();
                                        System.out.println("shield = " + PlayerShield);
                                    }
                                    else{
                                        JOptionPane.showMessageDialog(new JFrame(), "You've already equipped an armor.", "ALERT",
                                          JOptionPane.ERROR_MESSAGE );
                                        ComboBox.setSelectedIndex(4);
                                    }
                                }
                                case 2 -> {
                                    if(!isBootActive){
                                        isBootActive = true;
                                        if(gearSelection == 1)  movementSpeed = 5 ;
                                        else if(gearSelection == 2)  movementSpeed = 10 ;
                                        else if(gearSelection == 3)  movementSpeed = 15 ;
                                        System.out.println("speed = " + movementSpeed);
                                    }
                                    else{
                                        JOptionPane.showMessageDialog(new JFrame(), "You've already equipped boots.", "ALERT",
                                          JOptionPane.ERROR_MESSAGE );
                                        ComboBox.setSelectedIndex(4);
                                    }
                                }
                                case 3 -> {
                                    if(!isBulletActive){
                                        isBulletActive = true;
                                        if(gearSelection == 1)          PlayerDmg = 30 ;
                                        else if(gearSelection == 2)     PlayerDmg = 40 ;
                                        else if(gearSelection == 3)     PlayerDmg = 50 ;
                                        System.out.println("PlayerDmg = " + PlayerDmg);
                                    }
                                    else{
                                        JOptionPane.showMessageDialog(new JFrame(), "You've already equipped the magazine.", "ALERT",
                                          JOptionPane.ERROR_MESSAGE );
                                        ComboBox.setSelectedIndex(4);
                                    }
                                }
                                case 4 -> {
                                    if(!isGrenadeActive){
                                        isGrenadeActive = true;
                                        if(gearSelection == 1)          GrenadeDamage = 80 ;
                                        else if(gearSelection == 2)     GrenadeDamage = 160 ;
                                        else if(gearSelection == 3)     GrenadeDamage = 240 ;
                                        System.out.println("GrenadeDamage = " + GrenadeDamage);
                                    }
                                    else{
                                        JOptionPane.showMessageDialog(new JFrame(), "You've already equipped the grenades.", "ALERT",
                                          JOptionPane.ERROR_MESSAGE );
                                        ComboBox.setSelectedIndex(4);
                                    }
                                }
                            }
                        }
                        else if(e.getStateChange() == ItemEvent.DESELECTED){
                            switch((int)e.getItem()){
                                case 1 -> { shieldBar.setBounds(0, 0, 0, 0); PlayerShield = 0;  isArmorActive = false;}
                                case 2 -> { movementSpeed = 3;  isBootActive = false;}
                                case 3 -> { PlayerDmg = 20;     isBulletActive = false;}
                                case 4 -> { isGrenadeActive = false;}
                            }
                        }
            }

            public void resetEquipment(){
                shieldBar.setBounds(0, 0, 0, 0);
                PlayerShield = 0;
                movementSpeed = 3;
            }

            public class ComboBoxRenderar extends JLabel implements ListCellRenderer {

                public Component getListCellRendererComponent(JList list, 
                                                              Object value, 
                                                              int index, 
                                                              boolean isSelected, 
                                                              boolean cellHasFocus) {
                  int offset = ((Integer)value).intValue() - 1 ;

                  switch(gearSelection){
                      case 1 -> {MyImageIcon   IMG = equipmentList1[offset];    setIcon(IMG);   }
                      case 2 -> {MyImageIcon   IMG = equipmentList2[offset];    setIcon(IMG);   }
                      case 3 -> {MyImageIcon   IMG = equipmentList3[offset];    setIcon(IMG);   }
                  }

                  String        name = equipmentName[offset];   setText(name);

                  return this;
                }

            }
        }
        
    }
    
    class Scoreboard extends JFrame
    {
        
        private JLabel          drawpane;
        private JPanel          contentpane;
        private JLabel          logo;
        private MyImageIcon     backgroundImg,logoImg;
        
        public Scoreboard()
        {
            setTitle("Scoreboard");
            setBounds((frameWidth/2) - 300, 50, 600, frameHeight);
            getContentPane().setLayout(null);
            setResizable(false);
            setVisible(true);
            setDefaultCloseOperation( WindowConstants.DISPOSE_ON_CLOSE);
            
            contentpane = (JPanel)getContentPane();
            contentpane.setLayout( new BorderLayout() ); 

            Addscoreboard();
        }
        
        public void Addscoreboard()
        {
            logoImg = new MyImageIcon("resources/scoreIcon.PNG").resize(250, 250);
            backgroundImg = new MyImageIcon("resources/scoreBG.PNG").resize(600, frameHeight);
            
            try{
                Scanner s = new Scanner(new File("list.txt"));
                int i=0;
                while (s.hasNext()){
                    String line = s.nextLine();
                    String [] buf = line.split(",");  
                    list.add(new Score(Integer.parseInt(buf[1]),buf[0]));      
                    System.out.println(list.get(i).getName()+" "+list.get(i).getScore());
                    i++;
                }
                s.close();
            }
            catch(IOException e) {System.out.println(e);}
            Collections.sort(list);
            
            drawpane = new JLabel();
            drawpane.setIcon(backgroundImg);
            drawpane.setLayout(null);
            
            logo = new JLabel(logoImg);
            logo.setBounds(175 ,0,250, 200);
            drawpane.add(logo);
            
            JScrollPane scrollPane = new JScrollPane();
            scrollPane.setBounds(50, 170, 500, frameHeight - 250);
            getContentPane().add(scrollPane);
            
            JTable table = new JTable();
            scrollPane.setViewportView(table);
            DefaultTableModel model = (DefaultTableModel)table.getModel();
            
            model.addColumn("No.");
            model.addColumn("Name");
            model.addColumn("Score");
            
            System.out.println("list size = " + list.size());
            
            for(int i = 0; i<list.size(); i++){
                model.addRow(new Object[0]);
                model.setValueAt(i+1, i, 0);
                model.setValueAt(list.get(i).getName(), i, 1);
                model.setValueAt(list.get(i).score, i, 2);
            }
            
            drawpane.add(scrollPane);
            
            contentpane.add(drawpane, BorderLayout.CENTER);  

            validate();
        }
        
    }
    
    class MyImageIcon extends ImageIcon
    {
        public MyImageIcon(String fname)  { super(fname); }
        public MyImageIcon(Image image)   { super(image); }

        public MyImageIcon resize(int width, int height)
        {
            Image oldimg = this.getImage();
            Image newimg = oldimg.getScaledInstance(width, height, java.awt.Image.SCALE_SMOOTH);
            return new MyImageIcon(newimg);
        }
    };
    
    class MySoundEffect
    {
        private java.applet.AudioClip audio;

        public MySoundEffect(String filename)
        {
            try
            {
                java.io.File file = new java.io.File(filename);
                audio = java.applet.Applet.newAudioClip(file.toURL());
            }
            catch (Exception e) { e.printStackTrace(); }
        }
        public void playOnce()   { audio.play(); }
        public void playLoop()   { audio.loop(); }
        public void stop()       { audio.stop(); }
    }
    
}
