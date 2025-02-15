/ * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * 
 *     P r o j e c t . . . . . :     W i n d o w s   V i e w   ( N a m e s p a c e   E x t e n s i o n ) 
 * 
 *     A p p l i c a t i o n . :     W I N V I E W . d l l 
 *     M o d u l e . . . . . . :     U t i l i t y . h 
 *     D e s c r i p t i o n . :     H e l p e r   f u n c t i o n s   ( h e a d e r ) 
 * 
 *     C o m p i l e r . . . . :     M S   V i s u a l   C + +   
 *     W r i t t e n   b y . . :     D .   E s p o s i t o 
 * 
 *     E n v i r o n m e n t . :     W i n d o w s   9 x / N T 
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * / 
 
 
 # i f n d e f   U T I L I T Y _ H 
 # d e f i n e   U T I L I T Y _ H 
 
 
 # i n c l u d e   < w i n d o w s . h > 
 # i n c l u d e   < s h l o b j . h > 
 # i n c l u d e   < R e g s t r . h > 
 
 # i f d e f   _ c p l u s p l u s 
 e x t e r n   " C "   { 
 # e n d i f       / / _ c p l u s p l u s 
 
 
 / / e x t e r n   i n t     g _ n C o l u m n 1 ; 
 / / e x t e r n   i n t     g _ n C o l u m n 2 ; 
 / / e x t e r n   i n t     g _ n C o l u m n 3 ; 
 / / e x t e r n   i n t     g _ n C o l u m n 4 ; 
 
 
 t y p e d e f   s t r u c t   W N D I N F O   { 
 	 C H A R   p s z I n f o [ 1 0 2 4 ] ; 
 	 C H A R   s z C a p t i o n [ 1 0 0 ] ; 
 	 H I C O N   h I c o n ; 
 }   W N D I N F O ,   F A R * L P W N D I N F O ; 
 
 / /   r e g i s t r y   u t i l i t y   f u n c t i o n s 
 D W O R D   G e t K e y N a m e ( H K E Y ,   L P C T S T R ,   D W O R D ,   L P T S T R ,   D W O R D ) ; 
 B O O L   G e t V a l u e N a m e ( H K E Y ,   L P C T S T R ,   D W O R D ,   L P T S T R ,   D W O R D ) ; 
 
 / /   u t i l i t y   f u n c t i o n s 
 B O O L   S a v e G l o b a l S e t t i n g s (   V O I D   ) ; 
 B O O L   G e t G l o b a l S e t t i n g s (   V O I D   ) ; 
 I N T   C A L L B A C K   C o m p a r e I t e m s (   L P A R A M ,   L P A R A M ,   L P A R A M   ) ; 
 V O I D   C r e a t e I m a g e L i s t s (   V O I D   ) ; 
 V O I D   D e s t r o y I m a g e L i s t s (   V O I D   ) ; 
 I N T   W i d e C h a r T o L o c a l (   L P T S T R ,   L P W S T R ,   D W O R D   ) ; 
 I N T   L o c a l T o W i d e C h a r (   L P W S T R ,   L P T S T R ,   D W O R D   ) ; 
 V O I D   C l i p b o a r d C o p y (   L P S T R   ) ; 
 V O I D   G e t W i n d o w P r o p e r t i e s (   H W N D ,   L P W N D I N F O   ) ; 
 H I C O N   G e t W i n d o w I c o n (   H W N D ,   B O O L   ) ; 
 
 
 
 
 
 
 
 
 # i f d e f   _ c p l u s p l u s 
 } 
 # e n d i f       / / _ c p l u s p l u s 
 
 # i f n d e f   A R R A Y S I Z E 
 # d e f i n e   A R R A Y S I Z E ( a )         ( s i z e o f ( a ) / s i z e o f ( a [ 0 ] ) ) 
 # e n d i f 
 
 # e n d i f       / / U T I L I T Y _ H 
 