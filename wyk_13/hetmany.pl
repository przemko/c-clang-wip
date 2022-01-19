% hetmany.pl
%
% Program w SWI-Prologu rozwiązujący problem n-hetmanów.


:- use_module(library(clpfd)).

hetmany(N, P) :-
    model(N, P),
    labeling([ff], P).

model(N, P) :-
    length(P, N),
    P ins 1..N,
    all_different(P),
    bezpieczne(P).

bezpieczne([]).
bezpieczne([P | Ps]) :-
    nie_biją(Ps, P, 1),
    bezpieczne(Ps).

nie_biją([], _, _).
nie_biją([P1 | Ps], P2, Odleglość) :-
    Odleglość #\= abs(P1 - P2),
    Odleglość1 is Odleglość + 1,
    nie_biją(Ps, P2, Odleglość1).

% ?- time(hetmany(8, X)).
% 39,943 inferences, 0.005 CPU in 0.005 seconds (98% CPU, 8067663 Lips)
% X = [1, 5, 8, 6, 3, 7, 2, 4] .

% ?- time(hetmany(10, X)).
% 29,968 inferences, 0.004 CPU in 0.004 seconds (99% CPU, 7749677 Lips)
% X = [1, 3, 6, 9, 7, 10, 4, 2, 5|...] .

% ?- time(hetmany(20, X)).
% 169,296 inferences, 0.020 CPU in 0.020 seconds (98% CPU, 8621276 Lips)
% X = [1, 3, 5, 14, 17, 4, 16, 7, 12|...] .

% ?- time(hetmany(30, X)).
% 250,193 inferences, 0.026 CPU in 0.027 seconds (98% CPU, 9507981 Lips)
% X = [1, 3, 5, 24, 26, 4, 23, 7, 28|...] .

% ?- time(hetmany(100, X)).
% 2,108,713 inferences, 0.219 CPU in 0.232 seconds (94% CPU, 9647240 Lips)
% X = [1, 3, 5, 57, 59, 4, 64, 7, 58|...] .


