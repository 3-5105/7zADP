/ /   7 z A D P . c p p :   i m p l e m e n t a t i o n   o f   t h e   C 7 z A D P   c l a s s . 
 / / 
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
 # i f n d e f   U N I C O D E 
 # d e f i n e   U N I C O D E 
 # e n d i f 
 # i f n d e f   _ U N I C O D E 
 # d e f i n e   _ U N I C O D E 
 # e n d i f 
 # i n c l u d e   < w i n d o w s . h > 
 # i n c l u d e   < s h l o b j . h > 
 
 # i n c l u d e   " 7 z A D P . h " 
 
 # i n c l u d e   " C l a s s F a c t o r y . h " 
 # i n c l u d e   " U t i l i t y . h " 
 
 # i n c l u d e   < o l e c t l . h > 
 
 / /   d a t a 
 H I N S T A N C E       g _ h I n s t ; 
 U I N T                 g _ D l l R e f C o u n t ; 
 
 # p r a g m a   d a t a _ s e g ( " . t e x t " ) 
 # d e f i n e   I N I T G U I D 
 # i n c l u d e   < i n i t g u i d . h > 
 # i n c l u d e   < s h l g u i d . h > 
 # i n c l u d e   " G u i d . h " 
 # p r a g m a   d a t a _ s e g ( ) 
 
 B O O L   A P I E N T R Y   D l l M a i n (   H A N D L E   h M o d u l e ,   
                                               D W O R D     u l _ r e a s o n _ f o r _ c a l l ,   
                                               L P V O I D   l p R e s e r v e d 
 	 	 	 	 	   ) 
 { 
         s w i t c h   ( u l _ r e a s o n _ f o r _ c a l l ) 
 	 { 
 	 	 c a s e   D L L _ P R O C E S S _ A T T A C H : 
 	 	 	 g _ h I n s t   =   ( H I N S T A N C E ) h M o d u l e ; 
 	 	 c a s e   D L L _ T H R E A D _ A T T A C H : 
 	 	 c a s e   D L L _ T H R E A D _ D E T A C H : 
 	 	 c a s e   D L L _ P R O C E S S _ D E T A C H : 
 	 	 	 b r e a k ; 
         } 
         r e t u r n   T R U E ; 
 } 
 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 / /   D l l C a n U n l o a d N o w ( ) 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 S T D A P I   D l l C a n U n l o a d N o w (   V O I D   ) 
 { 
 	 r e t u r n   ( g _ D l l R e f C o u n t   ?   S _ F A L S E   :   S _ O K ) ; 
 } 
 
 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 / /   D l l G e t C l a s s O b j e c t ( ) 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 S T D A P I   D l l G e t C l a s s O b j e c t (   R E F C L S I D   r c l s i d ,   R E F I I D   r i i d ,   L P V O I D   * p p R e t u r n   ) 
 { 
 	 * p p R e t u r n   =   N U L L ; 
 
 	 / /   d o   w e   s u p p o r t   t h e   C L S I D ? 
 	 i f (   ! I s E q u a l C L S I D ( r c l s i d ,   C L S I D _ 7 z A D P )   ) 
 	       r e t u r n   C L A S S _ E _ C L A S S N O T A V A I L A B L E ; 
       
 	 / /   c a l l   t h e   f a c t o r y 
 	 C C l a s s F a c t o r y   * p C l a s s F a c t o r y   =   n e w   C C l a s s F a c t o r y ( ) ; 
 	 i f (   p C l a s s F a c t o r y = = N U L L   ) 
 	       r e t u r n   E _ O U T O F M E M O R Y ; 
       
 	 / /   q u e r y   i n t e r f a c e   f o r   t h e   a   p o i n t e r 
 	 H R E S U L T   h R e s u l t   =   p C l a s s F a c t o r y - > Q u e r y I n t e r f a c e ( r i i d ,   p p R e t u r n ) ; 
 	 p C l a s s F a c t o r y - > R e l e a s e ( ) ; 
 	 r e t u r n   h R e s u l t ; 
 } 
 
 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 / /   D l l G e t R e g i s t e r S e r v e r ( ) 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 
 t y p e d e f   s t r u c t { 
       H K E Y     h R o o t K e y ; 
       L P T S T R   l p s z S u b K e y ; 
       L P T S T R   l p s z V a l u e N a m e ; 
       L P T S T R   l p s z D a t a ; 
 } R E G S T R U C T ,   * L P R E G S T R U C T ; 
 
 S T D A P I   D l l R e g i s t e r S e r v e r (   V O I D   ) 
 { 
 	 I N T   i ; 
 	 H K E Y   h K e y ; 
 	 L R E S U L T   l R e s u l t ; 
 	 D W O R D   d w D i s p ; 
 	 W C H A R   s z S u b K e y [ M A X _ P A T H ] ; 
 	 W C H A R   s z C L S I D [ M A X _ P A T H ] ; 
 	 W C H A R   s z M o d u l e [ M A X _ P A T H ] ; 
 	 L P W S T R   p w s z ; 
 
 	 / /   g e t   t h e   C L S I D   i n   s t r i n g   f o r m 
 	 S t r i n g F r o m I I D ( C L S I D _ 7 z A D P ,   & p w s z ) ; 
 
 	 i f   ( p w s z ) 
 	 { 
 	 	 / /   �v�cY6R�[W[&{2N
 	 	 l s t r c p y n W ( s z C L S I D ,   p w s z ,   M A X _ P A T H ) ; 
 
 	 	 L P M A L L O C   p M a l l o c ; 
 	 	 C o G e t M a l l o c ( 1 ,   & p M a l l o c ) ; 
 	 	 i f   ( p M a l l o c ) 
 	 	 { 
 	 	 	 p M a l l o c - > F r e e ( p w s z ) ; 
 	 	 	 p M a l l o c - > R e l e a s e ( ) ; 
 	 	 } 
 	 } 
 
 	 / /   g e t   t h i s   D L L ' s   p a t h   a n d   f i l e   n a m e 
 	 G e t M o d u l e F i l e N a m e W ( g _ h I n s t ,   s z M o d u l e ,   M A X _ P A T H ) ; 
 
 	 / /   C L S I D   e n t r i e s   -   O(u�[W[&{2NW[b�ϑ
 	 s t r u c t   { 
 	 	 H K E Y     h R o o t K e y ; 
 	 	 L P C W S T R   l p s z S u b K e y ; 
 	 	 L P C W S T R   l p s z V a l u e N a m e ; 
 	 	 L P C W S T R   l p s z D a t a ; 
 	 }   C l s i d E n t r i e s [ ]   =   { 
 	 	 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s " ,                                     N U L L ,                                       L " 7 z A D P " , 
 	 	 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s " ,                                     L " I n f o T i p " ,                         L " 7 z A D P . " , 
 	 	 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s \ \ I n p r o c S e r v e r 3 2 " ,     N U L L ,                                     L " % s " , 
 	 	 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s \ \ I n p r o c S e r v e r 3 2 " ,     L " T h r e a d i n g M o d e l " ,           L " A p a r t m e n t " , 
 	 	 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s \ \ D e f a u l t I c o n " ,           N U L L ,                                     L " % s , 0 " , 
 	 	 N U L L ,                           N U L L ,                                                       N U L L ,                                       N U L L 
 	 } ; 
 
 	 f o r   ( i   =   0 ;   C l s i d E n t r i e s [ i ] . h R o o t K e y ;   i + + ) 
 	 { 
 	 	 / /   c r e a t e   t h e   s u b   k e y   s t r i n g 
 	 	 w s p r i n t f W ( s z S u b K e y ,   C l s i d E n t r i e s [ i ] . l p s z S u b K e y ,   s z C L S I D ) ; 
 	 	 l R e s u l t   =   R e g C r e a t e K e y E x W ( C l s i d E n t r i e s [ i ] . h R o o t K e y , 
 	 	 	 s z S u b K e y , 
 	 	 	 0 , 
 	 	 	 N U L L , 
 	 	 	 R E G _ O P T I O N _ N O N _ V O L A T I L E , 
 	 	 	 K E Y _ W R I T E , 
 	 	 	 N U L L , 
 	 	 	 & h K e y , 
 	 	 	 & d w D i s p ) ; 
 
 	 	 i f   ( l R e s u l t   = =   N O E R R O R ) 
 	 	 { 
 	 	 	 W C H A R   s z D a t a [ M A X _ P A T H ] ; 
 	 	 	 w s p r i n t f W ( s z D a t a ,   C l s i d E n t r i e s [ i ] . l p s z D a t a ,   s z M o d u l e ) ; 
 	 	 	 l R e s u l t   =   R e g S e t V a l u e E x W ( h K e y , 
 	 	 	 	 C l s i d E n t r i e s [ i ] . l p s z V a l u e N a m e , 
 	 	 	 	 0 , 
 	 	 	 	 R E G _ S Z , 
 	 	 	 	 ( L P B Y T E ) s z D a t a , 
 	 	 	 	 ( l s t r l e n W ( s z D a t a )   +   1 )   *   s i z e o f ( W C H A R ) ) ; 
 
 	 	 	 R e g C l o s e K e y ( h K e y ) ; 
 	 	 } 
 	 	 e l s e 
 	 	 	 r e t u r n   S E L F R E G _ E _ C L A S S ; 
 	 } 
 
 	 / /   C o n t e x t   M e n u   f o r   a l l   f i l e s 
 	 l s t r c p y W ( s z S u b K e y ,   L " * \ \ S h e l l E x \ \ C o n t e x t M e n u H a n d l e r s \ \ 7 z A D P " ) ; 
 	 l R e s u l t   =   R e g C r e a t e K e y E x W ( H K E Y _ C L A S S E S _ R O O T , 
 	 	 s z S u b K e y , 
 	 	 0 , 
 	 	 N U L L , 
 	 	 R E G _ O P T I O N _ N O N _ V O L A T I L E , 
 	 	 K E Y _ W R I T E , 
 	 	 N U L L , 
 	 	 & h K e y , 
 	 	 & d w D i s p ) ; 
 
 	 i f   ( l R e s u l t   = =   N O E R R O R ) 
 	 { 
 	 	 W C H A R   s z D a t a [ M A X _ P A T H ] ; 
 	 	 l s t r c p y W ( s z D a t a ,   s z C L S I D ) ; 
 	 	 l R e s u l t   =   R e g S e t V a l u e E x W ( h K e y , 
 	 	 	 N U L L , 
 	 	 	 0 , 
 	 	 	 R E G _ S Z , 
 	 	 	 ( L P B Y T E ) s z D a t a , 
 	 	 	 ( l s t r l e n W ( s z D a t a )   +   1 )   *   s i z e o f ( W C H A R ) ) ; 
 
 	 	 R e g C l o s e K e y ( h K e y ) ; 
 	 } 
 	 e l s e 
 	 	 r e t u r n   S E L F R E G _ E _ C L A S S ; 
 
 	 / /   r e g i s t e r   t h e   e x t e n s i o n   a s   a p p r o v e d   b y   N T 
 	 O S V E R S I O N I N F O     o s v i ; 
 	 o s v i . d w O S V e r s i o n I n f o S i z e   =   s i z e o f ( o s v i ) ; 
 	 G e t V e r s i o n E x ( & o s v i ) ; 
 
 	 i f   ( V E R _ P L A T F O R M _ W I N 3 2 _ N T   = =   o s v i . d w P l a t f o r m I d ) 
 	 { 
 	 	 l s t r c p y W ( s z S u b K e y ,   L " S o f t w a r e \ \ M i c r o s o f t \ \ W i n d o w s \ \ C u r r e n t V e r s i o n \ \ S h e l l   E x t e n s i o n s \ \ A p p r o v e d " ) ; 
 	 	 l R e s u l t   =   R e g C r e a t e K e y E x W ( H K E Y _ L O C A L _ M A C H I N E , 
 	 	 	 s z S u b K e y , 
 	 	 	 0 , 
 	 	 	 N U L L , 
 	 	 	 R E G _ O P T I O N _ N O N _ V O L A T I L E , 
 	 	 	 K E Y _ W R I T E , 
 	 	 	 N U L L , 
 	 	 	 & h K e y , 
 	 	 	 & d w D i s p ) ; 
 
 	 	 i f   ( l R e s u l t   = =   N O E R R O R ) 
 	 	 { 
 	 	 	 W C H A R   s z D a t a [ M A X _ P A T H ] ; 
 	 	 	 l s t r c p y W ( s z D a t a ,   L " 7 z A D P " ) ; 
 	 	 	 l R e s u l t   =   R e g S e t V a l u e E x W ( h K e y , 
 	 	 	 	 s z C L S I D , 
 	 	 	 	 0 , 
 	 	 	 	 R E G _ S Z , 
 	 	 	 	 ( L P B Y T E ) s z D a t a , 
 	 	 	 	 ( l s t r l e n W ( s z D a t a )   +   1 )   *   s i z e o f ( W C H A R ) ) ; 
 
 	 	 	 R e g C l o s e K e y ( h K e y ) ; 
 	 	 } 
 	 	 e l s e 
 	 	 	 r e t u r n   S E L F R E G _ E _ C L A S S ; 
 	 } 
 
 	 r e t u r n   S _ O K ; 
 } 
 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 / /   D l l U n r e g i s t e r S e r v e r ( ) 
 / * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - * / 
 S T D A P I   D l l U n r e g i s t e r S e r v e r ( V O I D ) 
 { 
         I N T   i ; 
         L R E S U L T   l R e s u l t ; 
         W C H A R   s z S u b K e y [ M A X _ P A T H ] ; 
         W C H A R   s z C L S I D [ M A X _ P A T H ] ; 
         W C H A R   s z M o d u l e [ M A X _ P A T H ] ; 
         L P W S T R   p w s z ; 
 
         / /   g e t   t h e   C L S I D   i n   s t r i n g   f o r m 
         S t r i n g F r o m I I D ( C L S I D _ 7 z A D P ,   & p w s z ) ; 
 
         i f   ( p w s z ) 
         { 
                 / /   �v�cY6R�[W[&{2N
                 l s t r c p y n W ( s z C L S I D ,   p w s z ,   M A X _ P A T H ) ; 
                 
                 L P M A L L O C   p M a l l o c ; 
                 C o G e t M a l l o c ( 1 ,   & p M a l l o c ) ; 
                 i f   ( p M a l l o c ) 
                 { 
                         p M a l l o c - > F r e e ( p w s z ) ; 
                         p M a l l o c - > R e l e a s e ( ) ; 
                 } 
         } 
 
         / /   g e t   t h i s   D L L ' s   p a t h   a n d   f i l e   n a m e 
         G e t M o d u l e F i l e N a m e W ( g _ h I n s t ,   s z M o d u l e ,   M A X _ P A T H ) ; 
 
         / /   C L S I D   e n t r i e s   -   O(u�[W[&{2NW[b�ϑ
         s t r u c t   { 
                 H K E Y     h R o o t K e y ; 
                 L P C W S T R   l p s z S u b K e y ; 
                 L P C W S T R   l p s z V a l u e N a m e ; 
                 L P C W S T R   l p s z D a t a ; 
         }   C l s i d E n t r i e s [ ]   =   { 
                 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s " ,                                     N U L L ,                                       L " 7 z A D P " , 
                 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s " ,                                     L " I n f o T i p " ,                         L " 7 z A D P . " , 
                 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s \ \ I n p r o c S e r v e r 3 2 " ,     N U L L ,                                     L " % s " , 
                 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s \ \ I n p r o c S e r v e r 3 2 " ,     L " T h r e a d i n g M o d e l " ,           L " A p a r t m e n t " , 
                 H K E Y _ C L A S S E S _ R O O T ,   L " C L S I D \ \ % s \ \ D e f a u l t I c o n " ,           N U L L ,                                     L " % s , 0 " , 
                 N U L L ,                           N U L L ,                                                       N U L L ,                                       N U L L 
         } ; 
 
         f o r   ( i   =   0 ;   C l s i d E n t r i e s [ i ] . h R o o t K e y ;   i + + ) 
         { 
                 / /   c r e a t e   t h e   s u b   k e y   s t r i n g 
                 w s p r i n t f W ( s z S u b K e y ,   C l s i d E n t r i e s [ i ] . l p s z S u b K e y ,   s z C L S I D ) ; 
                 l R e s u l t   =   R e g D e l e t e K e y W ( C l s i d E n t r i e s [ i ] . h R o o t K e y ,   s z S u b K e y ) ; 
         } 
 
         / /   C o n t e x t   M e n u 
         l s t r c p y W ( s z S u b K e y ,   L " * \ \ S h e l l E x \ \ C o n t e x t M e n u H a n d l e r s \ \ 7 z A D P " ) ; 
         l R e s u l t   =   R e g D e l e t e K e y W ( H K E Y _ C L A S S E S _ R O O T ,   s z S u b K e y ) ; 
 
         / /   r e g i s t e r   t h e   e x t e n s i o n   a s   a p p r o v e d   b y   N T 
         O S V E R S I O N I N F O     o s v i ; 
         o s v i . d w O S V e r s i o n I n f o S i z e   =   s i z e o f ( o s v i ) ; 
         G e t V e r s i o n E x ( & o s v i ) ; 
 
         i f   ( V E R _ P L A T F O R M _ W I N 3 2 _ N T   = =   o s v i . d w P l a t f o r m I d ) 
         { 
                 l s t r c p y W ( s z S u b K e y ,   L " S o f t w a r e \ \ M i c r o s o f t \ \ W i n d o w s \ \ C u r r e n t V e r s i o n \ \ S h e l l   E x t e n s i o n s \ \ A p p r o v e d " ) ; 
                 l R e s u l t   =   R e g D e l e t e K e y W ( H K E Y _ L O C A L _ M A C H I N E ,   s z S u b K e y ) ; 
         } 
 
         r e t u r n   S _ O K ; 
 } 