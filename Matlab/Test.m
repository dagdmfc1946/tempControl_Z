% s = tf('s');
% 
% % Definición de parámetros del sistema (Planta) identificada
% Kp = 0.11864; % Ganancia del sistema
% Tp1 = 170.65; % Tiempo de establecimiento
% L = 30; % Tiempo muerto o Delay
% P_s = ( (Kp * exp(-L*s) ) / ((Tp1*s) + 1) )    % Modelo identificado del sistema (Planta)
% P_fact = zpk(P_s)    % P_s factorizada
% 
% pade_firstOrder = pade(P_s,1)
% 
% zpk(pade_firstOrder)




% ----------------------------------




% s = tf('s');
% 
% 
% rta = (170.65*s + 1) + (0.11864 * ((-15*s + 1)/(15*s + 1)))
% 
% G_s = tf([0.11864], [170.65 1], 'InputDelay', 30)   % Otra forma de definir una FT
% 
% G_aprox = pade(G_s, 1)  % El '1' indica el orden de la Aproximación de Padé