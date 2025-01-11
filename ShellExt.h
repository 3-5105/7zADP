/ /   S h e l l E x t . h :   i n t e r f a c e   f o r   t h e   C S h e l l E x t   c l a s s . 
 / / 
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
 
 # i f   ! d e f i n e d ( A F X _ S H E L L E X T _ H _ _ 3 8 E F B 6 8 B _ 5 5 9 1 _ 4 8 5 A _ 9 E 5 0 _ 4 0 9 E 8 C D E 1 0 E 2 _ _ I N C L U D E D _ ) 
 # d e f i n e   A F X _ S H E L L E X T _ H _ _ 3 8 E F B 6 8 B _ 5 5 9 1 _ 4 8 5 A _ 9 E 5 0 _ 4 0 9 E 8 C D E 1 0 E 2 _ _ I N C L U D E D _ 
 
 # i f   _ M S C _ V E R   >   1 0 0 0 
 # p r a g m a   o n c e 
 # e n d i f   / /   _ M S C _ V E R   >   1 0 0 0 
 
 # i n c l u d e   < w i n d o w s . h > 
 
 # i f n d e f   U N I C O D E 
 # d e f i n e   U N I C O D E 
 # e n d i f 
 # i f n d e f   _ U N I C O D E 
 # d e f i n e   _ U N I C O D E 
 # e n d i f 
 
 # i n c l u d e   < s h l o b j . h > 
 
 e x t e r n   H I N S T A N C E   g _ h I n s t ; 
 
 c l a s s   C S h e l l E x t   :   p u b l i c   I S h e l l E x t I n i t ,   I C o n t e x t M e n u 
 { 
 p r o t e c t e d : 
 	 D W O R D   m _ O b j R e f C o u n t ; 
 	 W C H A R   ( * m _ p F i l e s ) [ M A X _ P A T H ] ;     / /   9e:N  W C H A R 
 	 U I N T   m _ n F i l e s ; 
 
 p u b l i c : 
 	 C S h e l l E x t ( ) ; 
 	 v i r t u a l   ~ C S h e l l E x t ( ) ; 
 
 	 / /   I U n k n o w n   m e t h o d s 
 	 S T D M E T H O D   ( Q u e r y I n t e r f a c e )   ( R E F I I D   r i i d ,   L P V O I D   *   p p v O b j ) ; 
 	 S T D M E T H O D _   ( U L O N G ,   A d d R e f )   ( v o i d ) ; 
 	 S T D M E T H O D _   ( U L O N G ,   R e l e a s e )   ( v o i d ) ; 
 	 
 
         / /   I S h e l l E x t I n i t 
         S T D M E T H O D I M P   I n i t i a l i z e ( L P C I T E M I D L I S T ,   L P D A T A O B J E C T ,   H K E Y ) ; 
 
         / /   I C o n t e x t M e n u 
         S T D M E T H O D I M P   G e t C o m m a n d S t r i n g ( U I N T _ P T R ,   U I N T ,   U I N T * ,   L P S T R ,   U I N T ) ; 
         S T D M E T H O D I M P   I n v o k e C o m m a n d ( L P C M I N V O K E C O M M A N D I N F O ) ; 
         S T D M E T H O D I M P   Q u e r y C o n t e x t M e n u ( H M E N U ,   U I N T ,   U I N T ,   U I N T ,   U I N T ) ; 
 } ; 
 
 # e n d i f   / /   ! d e f i n e d ( A F X _ S H E L L E X T _ H _ _ 3 8 E F B 6 8 B _ 5 5 9 1 _ 4 8 5 A _ 9 E 5 0 _ 4 0 9 E 8 C D E 1 0 E 2 _ _ I N C L U D E D _ ) 
 