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
    bezpieczne(P).

bezpieczne([]).
bezpieczne([P | Ps]) :-
    nie_biją(Ps, P, 1),
    bezpieczne(Ps).

nie_biją([], _, _).
nie_biją([P1 | Ps], P2, Odleglość) :-
    P1 #\= P2,
    Odleglość #\= abs(P1 - P2),
    Odleglość1 is Odleglość + 1,
    nie_biją(Ps, P2, Odleglość1).

% ?- time(hetmany(8, X)).
% 45,920 inferences, 0.006 CPU in 0.006 seconds (98% CPU, 7747596 Lips)
% X = [1, 5, 8, 6, 3, 7, 2, 4] .
%
% ?- time(hetmany(10, X)).
% 38,409 inferences, 0.005 CPU in 0.005 seconds (100% CPU, 8399082 Lips)
% X = [1, 3, 6, 9, 7, 10, 4, 2, 5|...] .
%
% ?- time(hetmany(20, X)).
% 208,083 inferences, 0.023 CPU in 0.024 seconds (99% CPU, 8896238 Lips)
% X = [1, 3, 5, 14, 17, 4, 16, 7, 12|...] .
%
% ?- time(hetmany(30, X)).
% 321,373 inferences, 0.035 CPU in 0.038 seconds (91% CPU, 9254003 Lips)
% X = [1, 3, 5, 24, 26, 4, 23, 7, 28|...] .

% ?- time(hetmany(100, X)).
% 2,833,429 inferences, 0.322 CPU in 0.336 seconds (96% CPU, 8811098 Lips)
% X = [1, 3, 5, 57, 59, 4, 64, 7, 58|...] .
