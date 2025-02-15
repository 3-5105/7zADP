/ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * 
 *     P r o j e c t . . . . . :     W i n d o w s   V i e w   ( N a m e s p a c e   E x t e n s i o n ) 
 * 
 *     A p p l i c a t i o n . :     W I N V I E W . d l l 
 *     M o d u l e . . . . . . :     U t i l i t y . c p p 
 *     D e s c r i p t i o n . :     H e l p e r   f u n c t i o n s   ( i m p l e m e n t a t i o n ) 
 * 
 *     C o m p i l e r . . . . :     M S   V i s u a l   C + +   
 *     W r i t t e n   b y . . :     D .   E s p o s i t o 
 * 
 *     E n v i r o n m e n t . :     W i n d o w s   9 x / N T 
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * / 
 
 # i n c l u d e   < w i n d o w s . h > 
 # i n c l u d e   < s h l o b j . h > 
 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 / /                                                 I N C L U D E   s e c t i o n 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 # i n c l u d e   " U t i l i t y . h " 
 / / # i n c l u d e   " S h e l l F o l d e r . h " 
 / / # i n c l u d e   " r e s o u r c e . h " 
 / / # i n c l u d e   " H w n d P r o c . h " 
 
 
 e x t e r n   H I M A G E L I S T   g _ h i m l S m a l l ; 
 
 # d e f i n e   M A I N _ K E Y _ S T R I N G                 ( T E X T ( " S o f t w a r e \ \ S h e l l E x t N o A t l " ) ) 
 # d e f i n e   V A L U E _ S T R I N G                       ( T E X T ( " D i s p l a y   S e t t i n g s " ) ) 
 
 # d e f i n e   I N I T I A L _ C O L U M N 1 _ S I Z E       1 0 0 	 / /   s t a t e 
 # d e f i n e   I N I T I A L _ C O L U M N 2 _ S I Z E       1 0 0 	 / /   c l a s s 
 # d e f i n e   I N I T I A L _ C O L U M N 3 _ S I Z E       6 0 	 / /   h w n d 
 # d e f i n e   I N I T I A L _ C O L U M N 4 _ S I Z E       1 0 0 	 / /   t i t l e 
 
 
 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 / /   R e g i s t r y   u t i l i t y 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 
 / /   G e t K e y N a m e 
 D W O R D   G e t K e y N a m e (   H K E Y   h K e y R o o t ,   L P C T S T R   p s z S u b K e y ,   D W O R D   d w I n d e x ,   
                                     L P T S T R   p s z O u t ,   D W O R D   d w S i z e   ) 
 { 
 	 H K E Y   h K e y ; 
 	 L O N G   l R e s u l t ; 
 	 F I L E T I M E   f t ; 
 
 	 i f (   ! p s z O u t   ) 
 	       r e t u r n   0 ; 
 
 	 i f (   ! p s z S u b K e y   ) 
 	       p s z S u b K e y   =   T E X T ( " " ) ; 
 
 	 / /   o p e n   t h e   s p e c i f i e d   k e y 
 	 l R e s u l t   =   R e g O p e n K e y E x (   h K e y R o o t ,   p s z S u b K e y ,   0 , 
 	 	 	 	 	 	 	 K E Y _ E N U M E R A T E _ S U B _ K E Y S ,   & h K e y ) ; 
 
 	 i f (   l R e s u l t   ! =   E R R O R _ S U C C E S S   ) 
 	       r e t u r n   0 ; 
 
 	 / /   g e t   t h e   s p e c i f i e d   s u b k e y 
 	 l R e s u l t   =   R e g E n u m K e y E x (   h K e y ,   d w I n d e x ,   p s z O u t ,   & d w S i z e , 
 	 	 	 	 	 	 	 N U L L ,   N U L L ,   N U L L ,   & f t   ) ; 
 	 R e g C l o s e K e y ( h K e y ) ; 
 
 	 i f (   l R e s u l t   = =   E R R O R _ S U C C E S S   ) 
 	       r e t u r n   d w S i z e ; 
 
 	 r e t u r n   0 ; 
 } 
 
 
 / /   G e t V a l u e N a m e 
 B O O L   G e t V a l u e N a m e (   H K E Y   h K e y R o o t ,   L P C T S T R   p s z S u b K e y ,   D W O R D   d w I n d e x ,   
         L P T S T R   p s z O u t ,   D W O R D   d w S i z e   ) 
 { 
 	 H K E Y   h K e y ; 
 	 L O N G   l R e s u l t ; 
 	 D W O R D   d w T y p e ; 
 
 	 i f (   ! p s z O u t   ) 
 	       r e t u r n   0 ; 
 
 	 i f (   ! p s z S u b K e y   ) 
 	       p s z S u b K e y   =   T E X T ( " " ) ; 
 
 	 / /   o p e n   t h e   s p e c i f i e d   k e y 
 	 l R e s u l t   =   R e g O p e n K e y E x (   h K e y R o o t ,   p s z S u b K e y ,   0 , 
 	 	 	 	 K E Y _ Q U E R Y _ V A L U E ,   & h K e y   ) ; 
 
 	 i f (   l R e s u l t   ! =   E R R O R _ S U C C E S S   ) 
 	       r e t u r n   0 ; 
 
 	 / /   g e t   t h e   s p e c i f i e d   s u b k e y 
 	 l R e s u l t   =   R e g E n u m V a l u e (   h K e y ,   d w I n d e x ,   p s z O u t ,   & d w S i z e ,   N U L L , 
                   & d w T y p e ,   N U L L ,   N U L L   ) ; 
 
 	 R e g C l o s e K e y ( h K e y ) ; 
 
 	 r e t u r n   ( l R e s u l t = = E R R O R _ S U C C E S S   ) ; 
 } 
 
 
 
 / /   S a v e G l o b a l S e t t i n g s 
 B O O L   S a v e G l o b a l S e t t i n g s (   V O I D   ) 
 { 
 	 H K E Y   h K e y ; 
 	 L O N G   l R e s u l t ; 
 	 D W O R D   d w D i s p ; 
 
 	 l R e s u l t   =   R e g C r e a t e K e y E x (     H K E Y _ C U R R E N T _ U S E R , 
                                           M A I N _ K E Y _ S T R I N G ,   
 	 	 	 	 	   0 , 
                                           N U L L , 
                                           R E G _ O P T I O N _ N O N _ V O L A T I L E ,   
                                           K E Y _ A L L _ A C C E S S , 
                                           N U L L ,   
                                           & h K e y , 
                                           & d w D i s p   ) ; 
 
 	 i f ( l R e s u l t   ! =   E R R O R _ S U C C E S S ) 
 	 	 r e t u r n   F A L S E ; 
 
 	 / /   c r e a t e   a n   a r r a y   t o   p u t   o u r   d a t a   i n 
 	 D W O R D   d w A r r a y [ 4 ] ; 
 	 / / d w A r r a y [ 0 ]   =   g _ n C o l u m n 1 ; 
 	 / / d w A r r a y [ 1 ]   =   g _ n C o l u m n 2 ; 
 	 / / d w A r r a y [ 2 ]   =   g _ n C o l u m n 3 ; 
 	 / / d w A r r a y [ 3 ]   =   g _ n C o l u m n 4 ; 
 	 d w A r r a y [ 4 ]   =   0 ; 
 
 	 l R e s u l t   =   R e g S e t V a l u e E x (   h K e y ,   V A L U E _ S T R I N G ,   0 ,   
                                     R E G _ B I N A R Y ,   ( L P B Y T E )   d w A r r a y ,   s i z e o f ( d w A r r a y )   ) ; 
 
 	 R e g C l o s e K e y (   h K e y   ) ; 
 
 	 i f (   l R e s u l t   ! =   E R R O R _ S U C C E S S   ) 
 	 	 r e t u r n   F A L S E ; 
 
 	 r e t u r n   T R U E ; 
 } 
 
 
 / /   G e t G l o b a l S e t t i n g s 
 B O O L   G e t G l o b a l S e t t i n g s (   V O I D   ) 
 { 
 	 H K E Y   h K e y ; 
 	 L O N G   l R e s u l t ; 
 
 	 / /   s e t   u p   t h e   d e f a u l t   d a t a 
 	 / / g _ n C o l u m n 1   =   I N I T I A L _ C O L U M N 1 _ S I Z E ; 
 	 / / g _ n C o l u m n 2   =   I N I T I A L _ C O L U M N 2 _ S I Z E ; 
 	 / / g _ n C o l u m n 3   =   I N I T I A L _ C O L U M N 3 _ S I Z E ; 
 	 / / g _ n C o l u m n 4   =   I N I T I A L _ C O L U M N 4 _ S I Z E ; 
 
 	 l R e s u l t   =   R e g O p e n K e y E x (   H K E Y _ C U R R E N T _ U S E R , 
                                                 M A I N _ K E Y _ S T R I N G , 
                                                 0 , 
                                                 K E Y _ A L L _ A C C E S S , 
                                                 & h K e y ) ; 
 
 	 i f (   l R e s u l t   ! =   E R R O R _ S U C C E S S   ) 
 	 	 r e t u r n   F A L S E ; 
 
 	 / /   c r e a t e   a n   a r r a y   t o   p u t   o u r   d a t a   i n 
 	 D W O R D   d w A r r a y [ 5 ] ; 
 	 D W O R D   d w T y p e ; 
 	 D W O R D   d w S i z e   =   s i z e o f ( d w A r r a y ) ; 
 
 	 / /   r e t r i e v e   s e t t i n g s 
 	 l R e s u l t   =   R e g Q u e r y V a l u e E x (   h K e y , 
                                                       V A L U E _ S T R I N G , 
                                                       N U L L , 
                                                       & d w T y p e , 
                                                       ( L P B Y T E ) d w A r r a y , 
                                                       & d w S i z e ) ; 
 
 	 R e g C l o s e K e y (   h K e y   ) ; 
 
 	 i f (   l R e s u l t   ! =   E R R O R _ S U C C E S S   ) 
 	 	 r e t u r n   F A L S E ; 
 
 	 / / g _ n C o l u m n 1   =   d w A r r a y [ 0 ] ; 
 	 / / g _ n C o l u m n 2   =   d w A r r a y [ 1 ] ; 
 	 / / g _ n C o l u m n 3   =   d w A r r a y [ 2 ] ; 
 	 / / g _ n C o l u m n 4   =   d w A r r a y [ 3 ] ; 
 	 / / g _ b S h o w I D W   =   d w A r r a y [ 4 ] ; 
 
 	 r e t u r n   T R U E ; 
 } 
 
 
 
 / /   C o m p a r e I t e m s   ( s o r t   l i s t v i e w   b y   P I D L / H W N D ) 
 i n t   C A L L B A C K   C o m p a r e I t e m s ( L P A R A M   l P a r a m 1 ,   L P A R A M   l P a r a m 2 ,   L P A R A M   l p D a t a ) 
 { 
       / / C S h e l l F o l d e r *   p F o l d e r   =   r e i n t e r p r e t _ c a s t < C S h e l l F o l d e r * > ( l p D a t a ) ; 
       / / i f ( ! p F o l d e r ) 
       / /       r e t u r n   0 ; 
 
       / / r e t u r n   p F o l d e r - > C o m p a r e I D s ( 0 ,   r e i n t e r p r e t _ c a s t < L P I T E M I D L I S T > ( l P a r a m 1 ) , 
       / /                                                             r e i n t e r p r e t _ c a s t < L P I T E M I D L I S T > ( l P a r a m 2 ) ) ; 
 	 r e t u r n   0 ; 
 } 
 
 
 / /   c r e a t e   i m a g e l i s t s   f o r   t h e   l i s t v i e w 
 V O I D   C r e a t e I m a g e L i s t s (   V O I D   ) 
 { 
 	 / / i f (   g _ h i m l S m a l l   ) 
 	 / /       I m a g e L i s t _ D e s t r o y (   g _ h i m l S m a l l   ) ; 
 
 	 / / / /   s e t   t h e   s m a l l   i m a g e   l i s t 
 	 / / g _ h i m l S m a l l   =   I m a g e L i s t _ C r e a t e (   1 6 ,   1 6 ,   I L C _ C O L O R D D B | I L C _ M A S K ,   4 ,   0   ) ; 
 	 / / i f (   g _ h i m l S m a l l   ) 
 	 / / { 
 	 / / 	 H I C O N   h I c o n ; 
 	 / /         h I c o n   =   ( H I C O N )   L o a d I m a g e (   g _ h I n s t ,   
 	 / / 	 	 M A K E I N T R E S O U R C E ( I D I _ W I N D O W ) ,   I M A G E _ I C O N ,   
 	 / / 	 	 1 6 ,   1 6 ,   L R _ D E F A U L T C O L O R   ) ; 
 	 / /       I m a g e L i s t _ A d d I c o n (   g _ h i m l S m a l l ,   h I c o n   ) ; 
 
 	 / /       h I c o n   =   ( H I C O N )   L o a d I m a g e (   g _ h I n s t ,   
 	 / / 	       M A K E I N T R E S O U R C E ( I D I _ P A R W N D ) ,   I M A G E _ I C O N ,   
 	 / / 	       1 6 ,   1 6 ,   L R _ D E F A U L T C O L O R   ) ; 
 	 / /       I m a g e L i s t _ A d d I c o n (   g _ h i m l S m a l l ,   h I c o n   ) ; 
 
 	 / /       h I c o n   =   ( H I C O N )   L o a d I m a g e (   g _ h I n s t ,   
 	 / / 	       M A K E I N T R E S O U R C E ( I D I _ W N D ) ,   I M A G E _ I C O N ,   
 	 / / 	       1 6 ,   1 6 ,   L R _ D E F A U L T C O L O R   ) ; 
 	 / /       I m a g e L i s t _ A d d I c o n (   g _ h i m l S m a l l ,   h I c o n   ) ; 
 	 / / 
 	 / / } 
 } 
 
 / /   D e s t r o y I m a g e L i s t s 
 V O I D   D e s t r o y I m a g e L i s t s (   V O I D   ) 
 { 
 	 / / i f (   g _ h i m l S m a l l   ) 
 	 / / 	 I m a g e L i s t _ D e s t r o y (   g _ h i m l S m a l l   ) ; 
 } 
 
 
 / /   W i d e C h a r T o L o c a l 
 I N T   W i d e C h a r T o L o c a l ( L P T S T R   p L o c a l ,   L P W S T R   p W i d e ,   D W O R D   d w C h a r s ) 
 { 
 # i f d e f   U N I C O D E 
         / /   (W  U n i c o d e   �g�^-N��v�cY6R�[W[&{2N
         l s t r c p y n W ( p L o c a l ,   p W i d e ,   d w C h a r s ) ; 
         r e t u r n   l s t r l e n W ( p L o c a l ) ; 
 # e l s e 
         / /   (W  A N S I   �g�^-N�l�bc:NYW[��W[&{2N
         * p L o c a l   =   0 ; 
         W i d e C h a r T o M u l t i B y t e ( C P _ A C P ,   0 ,   p W i d e ,   - 1 ,   p L o c a l ,   d w C h a r s ,   N U L L ,   N U L L ) ; 
         r e t u r n   l s t r l e n A ( p L o c a l ) ; 
 # e n d i f 
 } 
 
 
 
 / /   L o c a l T o W i d e C h a r 
 I N T   L o c a l T o W i d e C h a r ( L P W S T R   p W i d e ,   L P T S T R   p L o c a l ,   D W O R D   d w C h a r s ) 
 { 
 # i f d e f   U N I C O D E 
         / /   (W  U n i c o d e   �g�^-N��v�cY6R�[W[&{2N
         l s t r c p y n W ( p W i d e ,   p L o c a l ,   d w C h a r s ) ; 
         r e t u r n   l s t r l e n W ( p W i d e ) ; 
 # e l s e 
         / /   (W  A N S I   �g�^-N�l�bc:N�[W[&{2N
         * p W i d e   =   0 ; 
         M u l t i B y t e T o W i d e C h a r ( C P _ A C P ,   0 ,   p L o c a l ,   - 1 ,   p W i d e ,   d w C h a r s ) ; 
         r e t u r n   l s t r l e n W ( p W i d e ) ; 
 # e n d i f 
 } 
 
 
 / /   C l i p b o a r d C o p y 
 V O I D   C l i p b o a r d C o p y (   L P S T R   s z T e x t   ) 
 { 
 	 O p e n C l i p b o a r d (   N U L L   ) ; 
 
 	 H A N D L E   h m e m   =   G l o b a l A l l o c (   G H N D ,   M A X _ P A T H   ) ; 
 	 L P S T R   p   =   ( L P S T R )   G l o b a l L o c k (   h m e m   ) ;   
 	 l s t r c p y (   p ,   ( L P S T R )   s z T e x t   ) ; 
 	 G l o b a l U n l o c k (   h m e m   ) ; 
 	 S e t C l i p b o a r d D a t a (   C F _ T E X T ,   h m e m   ) ; 
 
 	 C l o s e C l i p b o a r d ( ) ; 
 } 
 
 
 / /   G e t W i n d o w P r o p e r t i e s 
 V O I D   G e t W i n d o w P r o p e r t i e s (   H W N D   h w n d ,   L P W N D I N F O   l p w i   ) 
 { 
 	 / / Z e r o M e m o r y (   l p w i ,   s i z e o f ( W N D I N F O )   ) ; 
 
 	 / / / /   g e t   c l a s s   n a m e   a n d   t i t l e 
 	 / / C H A R   s z C l a s s [ 1 2 0 ] ,   s z T i t l e [ M A X _ P A T H ] ; 
 	 / / G e t C l a s s N a m e (   h w n d ,   s z C l a s s ,   1 2 0   ) ; 
 	 / / G e t W i n d o w T e x t (   h w n d ,   s z T i t l e ,   M A X _ P A T H   ) ; 
 	 / / i f (   ! l s t r l e n ( s z T i t l e )   ) 
 	 / / 	 w s p r i n t f (   s z T i t l e ,   " T h e   w i n d o w   h a s   n o   t i t l e "   ) ; 
 	 / / e l s e 
 	 / / { 
 	 / / 	 C H A R   t e m p [ M A X _ P A T H ] ; 
 	 / / 	 l s t r c p y (   t e m p ,   s z T i t l e   ) ; 
 	 / / 	 w s p r i n t f (   s z T i t l e ,   " T i t l e   i s   ' % s ' " ,   t e m p   ) ; 
 	 / / } 
 
 	 / / / /   g e t   t h e   r e c t a n g l e 
 	 / / R E C T   r c ; 
 	 / / G e t W i n d o w R e c t (   h w n d ,   & r c   ) ; 
 
 	 / / / /   g e t   t h e   I D 
 	 / / U I N T   u I D ; 
 	 / / u I D   =   G e t W i n d o w L o n g (   h w n d ,   G W L _ I D   ) ; 
 
 	 / / / /   g e t   p r o c e s s   a n d   t h r e a d 
 	 / / D W O R D   d w T h r e a d ,   d w P r o c e s s ; 
 	 / / d w T h r e a d   =   G e t W i n d o w T h r e a d P r o c e s s I d (   h w n d ,   & d w P r o c e s s   ) ; 
 	 / / C H A R   s z E x e F i l e [ M A X _ P A T H ] ; 
 	 / / G e t P r o g r a m F r o m H w n d (   h w n d ,   s z E x e F i l e ,   M A X _ P A T H   ) ; 
 
 
 	 / / / /   f o r m a t   t h e   r e t u r n   s t r i n g 
 	 / / C H A R   s 1 [ 1 0 0 ] ,   s 2 [ 1 0 0 ] ,   s 3 [ 3 0 0 ] ; 
 	 / / w s p r i n t f (   s 1 ,   " H a n d l e   i s   0 x % 0 4 X . \ r \ n I D   i s   0 x % 0 4 X . \ r \ n C l a s s   i s   ' % s ' . \ r \ n % s . \ r \ n P a r e n t   W i n d o w   i s   0 x % 0 4 X ,   O w n e r   i s   0 x % 0 4 X . " , 
 	 / / 	 	 h w n d ,   u I D ,   s z C l a s s ,   s z T i t l e ,   
 	 / / 	 	 G e t P a r e n t ( h w n d ) ,   G e t W i n d o w ( h w n d ,   G W _ O W N E R )   ) ;   
 	 / / w s p r i n t f (   s 2 ,   " \ r \ n I t   o c c u p i e s   a n   a r e a   t h a t   g o e s   f r o m   % d , % d   t o   % d , % d . \ r \ n W i d t h = % d ,   H e i g h t = % d . " , 
 	 / / 	 	 r c . l e f t ,   r c . t o p ,   r c . r i g h t ,   r c . b o t t o m ,   
 	 / / 	 	 r c . r i g h t - r c . l e f t ,   r c . b o t t o m - r c . t o p   ) ; 
 	 / / w s p r i n t f (   s 3 ,   " \ r \ n \ r \ n C r e a t e d   b y :   % s \ r \ n P r o c e s s   I D   i s   0 x % 0 8 X ,   T h r e a d   I D   i s   0 x % 0 8 X . " , 
 	 / / 	 	 s z E x e F i l e ,   d w P r o c e s s ,   d w T h r e a d   ) ; 
 	 / / l s t r c a t (   s 1 ,   s 2   ) ; 
 	 / / l s t r c a t (   s 1 ,   s 3   ) ; 
 	 / / l s t r c p y (   l p w i - > p s z I n f o ,   s 1   ) ; 
 
 	 / / / /   s e t   a   p o s s i b l e   c a p t i o n 
 	 / / G e t C l a s s N a m e (   h w n d ,   s z C l a s s ,   1 2 0   ) ; 
 	 / / G e t W i n d o w T e x t (   h w n d ,   s z T i t l e ,   M A X _ P A T H   ) ; 
 	 / / i f (   l s t r l e n ( s z T i t l e )   ) 
 	 / / 	 w s p r i n t f (   l p w i - > s z C a p t i o n ,   " I n f o :   ' % s '   [ % s ] " ,   s z T i t l e ,   s z C l a s s   ) ; 
 	 / / e l s e 
 	 / / 	 w s p r i n t f (   l p w i - > s z C a p t i o n ,   " I n f o :   < N o   t i t l e >   [ % s ] " ,   s z C l a s s   ) ; 
 
 	 / / / /   g e t   t h e   i c o n   ( i f   a n y ) 
 	 / / l p w i - > h I c o n   =   G e t W i n d o w I c o n (   h w n d ,   T R U E   ) ; 
 } 
 
 
 / /   G e t W i n d o w I c o n 
 / /   R e t u r n s   a   c o p y   o f   t h e   l a r g e / s m a l l   i c o n   f o r   t h e   s p e c i f i e d   w i n d o w ,   o r   a 
 / /     s t a n d a r d   i c o n   i f   t h e r e ' s   n o   i c o n   f o r   t h e   w i n d o w   c l a s s   i t   b e l o n g s   t o . 
 H I C O N   G e t W i n d o w I c o n ( H W N D   h w n d ,   B O O L   f B i g ) 
 { 
       H I C O N   h I c o n   =   N U L L ; 
 
       / / / /   F i r s t   s e a r c h   f o r   t h e   i c o n   a s s i g n e d   t o   t h e   w i n d o w   c l a s s .   I f   n o   i c o n   i s 
       / / / /     f o u n d ,   t h e n   I   t r y   t o   g e t   t h e   i c o n   a s s i g n e d   t o   t h e   s p e c i f i c   w i n d o w   v i a 
       / / / /     W M _ S E T I C O N .   I n   c a s e   o f   f u r t h e r   f a i l u r e ,   a   s t a n d a r d   i c o n   i s   r e t u r n e d . 
       / / i f ( f B i g ) 
       / / { 
       / /       / /   A   l a r g e   i c o n   i s   r e q u i r e d 
       / /       h I c o n   =   r e i n t e r p r e t _ c a s t < H I C O N > ( G e t C l a s s L o n g ( h w n d ,   G C L P _ H I C O N ) ) ; 
       / /       i f ( h I c o n   = =   N U L L ) 
       / /             h I c o n   =   r e i n t e r p r e t _ c a s t < H I C O N > ( S e n d M e s s a g e ( h w n d ,   W M _ G E T I C O N ,   I C O N _ B I G ,   0 ) ) ; 
       / / } 
       / / e l s e 
       / / { 
       / /       h I c o n   =   r e i n t e r p r e t _ c a s t < H I C O N > ( G e t C l a s s L o n g ( h w n d ,   G C L P _ H I C O N S M ) ) ; 
       / /       i f ( h I c o n   = =   N U L L ) 
       / /             h I c o n   =   r e i n t e r p r e t _ c a s t < H I C O N > ( S e n d M e s s a g e ( h w n d ,   W M _ G E T I C O N ,   I C O N _ S M A L L ,   0 ) ) ; 
       / / } 
 
       / / i f ( h I c o n   = =   N U L L ) 
       / /       h I c o n   =   L o a d I c o n ( g _ h I n s t ,   M A K E I N T R E S O U R C E ( I D I _ P A R W N D ) ) ; 
 
       / /   R e t u r n   a   c o p y   o f   t h e   i c o n 
       r e t u r n   C o p y I c o n ( h I c o n ) ; 
 } 
 
 
 / *     E n d   o f   f i l e :   U t i l i t y . c p p     * / 
 
 