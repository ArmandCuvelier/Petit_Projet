$(document).ready(function () {
    $('.Inscription').addClass('caché');
    $('.but1').addClass('desactivé');
    $('.but2').addClass('activé');
    $('.but1').click(function () {
        $('.Connexion').addClass('caché');
        $('.Inscription').removeClass('caché');
        $('.but1').removeClass('desactivé').addClass('activé');
        $('.but2').removeClass('activé').addClass('desactivé');
    });
    $('.but2').click(function () {
        $('.Inscription').addClass('caché');
        $('.Connexion').removeClass('caché');
        $('.but2').removeClass('desactivé').addClass('activé');
        $('.but1').removeClass('activé').addClass('desactivé');
    });
});