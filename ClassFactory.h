/ /   C l a s s F a c t o r y . h :   i n t e r f a c e   f o r   t h e   C C l a s s F a c t o r y   c l a s s . 
 / / 
 / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / 
 
 # i f   ! d e f i n e d ( A F X _ C L A S S F A C T O R Y _ H _ _ 3 B 4 B 8 B 3 0 _ 5 B 1 6 _ 4 B 6 9 _ A C C 8 _ 2 5 C 7 2 5 9 A 9 F 7 4 _ _ I N C L U D E D _ ) 
 # d e f i n e   A F X _ C L A S S F A C T O R Y _ H _ _ 3 B 4 B 8 B 3 0 _ 5 B 1 6 _ 4 B 6 9 _ A C C 8 _ 2 5 C 7 2 5 9 A 9 F 7 4 _ _ I N C L U D E D _ 
 
 # i f   _ M S C _ V E R   >   1 0 0 0 
 # p r a g m a   o n c e 
 # e n d i f   / /   _ M S C _ V E R   >   1 0 0 0 
 
 e x t e r n   H I N S T A N C E     g _ h I n s t ; 
 e x t e r n   U I N T               g _ D l l R e f C o u n t ; 
 
 c l a s s   C C l a s s F a c t o r y   :   p u b l i c   I C l a s s F a c t o r y     
 { 
 p r o t e c t e d : 
 	 D W O R D   m _ O b j R e f C o u n t ; 
 p u b l i c : 
 	 C C l a s s F a c t o r y ( ) ; 
 	 v i r t u a l   ~ C C l a s s F a c t o r y ( ) ; 
 
       / / I U n k n o w n   m e t h o d s 
       S T D M E T H O D I M P   Q u e r y I n t e r f a c e ( R E F I I D ,   L P V O I D * ) ; 
       S T D M E T H O D I M P _ ( D W O R D )   A d d R e f ( ) ; 
       S T D M E T H O D I M P _ ( D W O R D )   R e l e a s e ( ) ; 
 
       / / I C l a s s F a c t o r y   m e t h o d s 
       S T D M E T H O D I M P   C r e a t e I n s t a n c e ( L P U N K N O W N ,   R E F I I D ,   L P V O I D * ) ; 
       S T D M E T H O D I M P   L o c k S e r v e r ( B O O L )   {   r e t u r n   E _ N O T I M P L ;   } ; 
 } ; 
 
 # e n d i f   / /   ! d e f i n e d ( A F X _ C L A S S F A C T O R Y _ H _ _ 3 B 4 B 8 B 3 0 _ 5 B 1 6 _ 4 B 6 9 _ A C C 8 _ 2 5 C 7 2 5 9 A 9 F 7 4 _ _ I N C L U D E D _ ) 
 