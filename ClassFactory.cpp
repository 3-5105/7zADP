/ /   C l a s s F a c t o r y . c p p :   i m p l e m e n t a t i o n   o f   t h e   C C l a s s F a c t o r y   c l a s s . 
 / / 
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
 # i n c l u d e   < w i n d o w s . h > 
 # i n c l u d e   < s h l o b j . h > 
 
 # i n c l u d e   " C l a s s F a c t o r y . h " 
 
 # i n c l u d e   " S h e l l E x t . h " 
 
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
 / /   C o n s t r u c t i o n / D e s t r u c t i o n 
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
 
 C C l a s s F a c t o r y : : C C l a s s F a c t o r y ( ) 
 { 
 	 m _ O b j R e f C o u n t   =   1 ; 
 	 g _ D l l R e f C o u n t + + ; 
 } 
 
 C C l a s s F a c t o r y : : ~ C C l a s s F a c t o r y ( ) 
 { 
 	 g _ D l l R e f C o u n t - - ; 
 } 
 
 S T D M E T H O D I M P   C C l a s s F a c t o r y : : Q u e r y I n t e r f a c e (   R E F I I D   r i i d ,   L P V O I D   * p p R e t u r n   ) 
 { 
 	 * p p R e t u r n   =   N U L L ; 
 
 	 i f (   I s E q u a l I I D ( r i i d ,   I I D _ I U n k n o w n )   ) 
 	 	 * p p R e t u r n   =   t h i s ; 
 	 e l s e   
 	 	 i f (   I s E q u a l I I D ( r i i d ,   I I D _ I C l a s s F a c t o r y )   ) 
 	 	 	 * p p R e t u r n   =   ( I C l a s s F a c t o r y * ) t h i s ; 
 
 
 	 i f (   * p p R e t u r n   ) 
 	 { 
 	 	 L P U N K N O W N   p U n k   =   ( L P U N K N O W N ) ( * p p R e t u r n ) ; 
 	 	 p U n k - > A d d R e f ( ) ; 
 	 	 r e t u r n   S _ O K ; 
 	 } 
 
 	 r e t u r n   E _ N O I N T E R F A C E ; 
 } 
 
 S T D M E T H O D I M P _ ( D W O R D )   C C l a s s F a c t o r y : : A d d R e f ( ) 
 { 
 	 r e t u r n   + + m _ O b j R e f C o u n t ; 
 } 
 
 S T D M E T H O D I M P _ ( D W O R D )   C C l a s s F a c t o r y : : R e l e a s e ( ) 
 { 
 	 i f ( - - m _ O b j R e f C o u n t   = =   0 ) 
 	 { 
 	 	 d e l e t e   t h i s ; 
 	 	 r e t u r n   0 ; 
 	 } 
 
 	 r e t u r n   m _ O b j R e f C o u n t ; 
 } 
 
 S T D M E T H O D I M P   C C l a s s F a c t o r y : : C r e a t e I n s t a n c e (   L P U N K N O W N   p U n k n o w n ,   R E F I I D   r i i d ,   L P V O I D   * p p O b j e c t   ) 
 { 
 	 * p p O b j e c t   =   N U L L ; 
 	 i f (   p U n k n o w n   ! =   N U L L   ) 
 	 	 r e t u r n   C L A S S _ E _ N O A G G R E G A T I O N ; 
 
 	 / /   c r e a t e s   t h e   n a m e s p a c e ' s   m a i n   c l a s s 
 	 C S h e l l E x t   * p S h e l l E x t   =   n e w   C S h e l l E x t ( ) ; 
 	 i f (   N U L L = = p S h e l l E x t   )   
 	 	 r e t u r n   E _ O U T O F M E M O R Y ; 
 
 	 / /   q u e r y   i n t e r f a c e   f o r   t h e   r e t u r n   v a l u e 
 	 H R E S U L T   h R e s u l t   =   p S h e l l E x t - > Q u e r y I n t e r f a c e ( r i i d ,   p p O b j e c t ) ; 
 	 p S h e l l E x t - > R e l e a s e ( ) ; 
 	 r e t u r n   h R e s u l t ; 
 } 
 