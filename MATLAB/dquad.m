function I = dquad(d,fun)

relTol = 0.01;         % relative tolerance (1%)
maxSamples = 5e6;      % maximum total samples to draw
batchSize = 2000;      % samples per batch (adjustable)
minSamples = 1000;     % minimum samples before checking tolerance

x0 = rand(1,d);
f0 = fun(x0);
if ~isnumeric(f0) || ~isscalar(f0) || ~isreal(f0)
    error('fun must return a real scalar for a row-vector input of length d.');
end

% Initialize Welford online stats with the first sample
n = 1;
meanF = f0;
M2 = 0; % sum of squared deviations
    while true
        m= min(batchSize, maxSamples - n);;
        if( m<=0)
            break;
        end
        for i=  1:m
            x=rand(1,d);
            fx=fun(x);
            n=n+1;
            delta=fx-meanF;
            meanF=meanF+delta/n;     
            M2 = M2 + delta * (fx - meanF);
        end
        if n >= minSamples && n > 1
        s2 = M2 / (n - 1);        % sample variance (unbiased)
        se = sqrt(s2 / n);       % standard error of the mean
        if abs(meanF) > eps
            relErr = se / abs(meanF);
        else
            relErr = Inf;
        end
        if relErr <= relTol
            I = meanF;
            return;
        end
    end
        I=meanF;   
end
